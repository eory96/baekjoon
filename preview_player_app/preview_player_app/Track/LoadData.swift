//
//  loadData.swift
//  preview_player_app
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

import UIKit
import AVFoundation
class LoadData {
    var tracks: [AVPlayerItem] = []
    var songs: [Track] = []
    var todaysTrack: AVPlayerItem?
    
    init() {
        LoadData.search(){ songs in
            print("--> 몇개 넘어왔어?? \(songs.count), 첫번째꺼 제목: \(String(describing: songs.first?.title))")
            DispatchQueue.main.async {
                self.songs = songs
            }
        }
        
//        let tracks = loadTracks()
//        self.tracks = tracks
//        self.albums = loadAlbums(tracks: tracks)
//        self.todaysTrack = self.tracks.randomElement()
    }
    
    static func search(completion: @escaping ([Track]) -> Void) {
        let session = URLSession(configuration: .default)
        var urlComponents = URLComponents(string: "https://itunes.apple.com/search?")!
        let mediaQueryItem = URLQueryItem(name: "media", value: "music")
        let entityQueryItem = URLQueryItem(name: "entity", value: "song")
        let termQuery = URLQueryItem(name: "term", value: "IU")
        urlComponents.queryItems?.append(mediaQueryItem)
        urlComponents.queryItems?.append(entityQueryItem)
        urlComponents.queryItems?.append(termQuery)
        
        let requestURL = urlComponents.url!
        
        let dataTask = session.dataTask(with: requestURL) { data, response, error in
            let successRange = 200..<300
            guard error == nil,
                let statusCode = (response as? HTTPURLResponse)?.statusCode,
                successRange.contains(statusCode) else {
                    completion([])
                    return
            }
            
            guard let resultData = data else {
                completion([])
                return
            }
            
            let songs = LoadData.parseSongs(resultData)
            completion(songs)
        }
        dataTask.resume()
    }
    
    static func parseSongs(_ data: Data) -> [Track] {
        let decoder = JSONDecoder()

        do {
            let response = try decoder.decode(Response.self, from: data)
            let songs = response.results
            return songs
        } catch let error {
            print("--> parsing error: \(error.localizedDescription)")
            return []
        }
    }
}
