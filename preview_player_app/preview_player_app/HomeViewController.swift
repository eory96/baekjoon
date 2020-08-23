//
//  HomeViewController.swift
//  preview_player_app
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

import UIKit
import AVFoundation
import Kingfisher

class HomeViewController: UIViewController {
    let songManager: LoadData = LoadData()
    var songs: [Track] = []
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        print("1")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        songs = songManager.songs
        print("2")
        // Do any additional setup after loading the view.
    }
}

extension HomeViewController : UICollectionViewDelegateFlowLayout{
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        // 20 - card(width) - 20 - card(width) - 20
        let width: CGFloat = (collectionView.bounds.width - (20 * 3))/2
        let height: CGFloat = width + 60
        return CGSize(width: width, height: height)
    }
}

//클릭했을때의 작업을 의미
extension HomeViewController : UICollectionViewDelegate{
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let ps = UIStoryboard.init(name: "Player", bundle: nil)
        guard let playerVC = ps.instantiateViewController(identifier: "PlayerViewController") as? PlayerViewController else {
            return
        }
        
        let item = songs[indexPath.item]
        present(playerVC, animated: true, completion: nil)
    }
}

extension HomeViewController : UICollectionViewDataSource{
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return songs.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell  = collectionView.dequeueReusableCell(withReuseIdentifier: "TrackCollecionViewCell", for: indexPath) as? TrackCollectionViewCell else {
            print("else")
            return UICollectionViewCell()
        }
        
        let item = songs[indexPath.item]
        cell.updateUI(item: item)
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        switch kind {
        case UICollectionView.elementKindSectionHeader:
            guard let item = songs.randomElement() else {
                return UICollectionReusableView()
            }
            
            guard let header = collectionView.dequeueReusableSupplementaryView(ofKind: kind, withReuseIdentifier: "TrackCollectionHeaderView", for: indexPath) as? TrackCollectionHeaderView else{
                return UICollectionReusableView()
            }
            
            header.update(item)
            
            return header
        default:
            return UICollectionReusableView()
        }
    }
}

class LoadData {
    var tracks: [AVPlayerItem] = []
    var songs: [Track] = []
    var todaysTrack: AVPlayerItem?
    let queue = DispatchQueue(label: "zedd")

    init() {
        print("bye")
        LoadData.search(){ songs in
            print("--> 몇개 넘어왔어?? \(songs.count), 첫번째꺼 제목: \(String(describing: songs.first?.title))")
            self.queue.sync {
                self.songs = songs
            }
        }
        print("\(self.songs)")
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


struct Response: Codable {
    let resultCount: Int
    let results : [Track]
}
//CodingKey를 사용해서 내가 원하는 이름써서 key 사용하는 방법임

struct Track: Codable {
    let title: String
    let artistName: String
    let thumbnailPath : String
    let music: String
    
    enum CodingKeys: String, CodingKey {
        case title = "trackName"
        case artistName
        case thumbnailPath = "artworkUrl100"
        case music = "previewUrl"
    }
}
