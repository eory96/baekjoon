//
//  TrackCollectionViewCell.swift
//  preview_player_app
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

import UIKit
import Kingfisher

class TrackCollectionViewCell: UICollectionViewCell {
    @IBOutlet weak var thumbNailImage : UIImageView!
    @IBOutlet weak var titleLabel : UILabel!
    @IBOutlet weak var artistLabel : UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        thumbNailImage.layer.cornerRadius = 4
        artistLabel.textColor = UIColor.systemGray2
    }
    
    func updateUI(item :Track?) {
        print("hi")
        guard  let track = item else {return}
        
        let url = URL(string: track.thumbnailPath)!
        
        titleLabel.text = track.title
        
        artistLabel.text = track.artistName
        thumbNailImage.kf.setImage(with: url)
    }
}
