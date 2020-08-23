//
//  TrackCollectionHeaderView.swift
//  preview_player_app
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

import UIKit
import AVFoundation
import Kingfisher

class TrackCollectionHeaderView:UICollectionReusableView{
    @IBOutlet weak var thumbnailImageView: UIImageView!
    @IBOutlet weak var descriptionLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        thumbnailImageView.layer.cornerRadius = 4
    }

    func update(_ item: Track?) {
        guard let track = item else{return}
        let url = URL(string: track.thumbnailPath)!
        
        self.descriptionLabel.text = "Today's pick is \(track.artistName)'s album - \(track.title), Let's listen."
        descriptionLabel.adjustsFontSizeToFitWidth = false
        descriptionLabel.lineBreakMode = .byTruncatingTail
        self.thumbnailImageView.kf.setImage(with: url)
    }
}
