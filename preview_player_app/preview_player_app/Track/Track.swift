//
//  Track.swift
//  preview_player_app
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

import UIKit

struct Response: Codable {
    let resultCount: Int
    let results : [Track]
    
//    enum CodingKeys: String, CodingKey {
//        case resultCount
//        case tracks = "results"
//    }
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
