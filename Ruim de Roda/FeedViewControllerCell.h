//
//  FeedViewControllerCell.h
//  Ruim de Roda
//
//  Created by Henrique Velloso on 4/11/15.
//  Copyright (c) 2015 Ruim de Roda. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

@interface FeedViewControllerCell : UITableViewCell


@property (weak, nonatomic) IBOutlet UIView *imgPhoto;
@property (weak, nonatomic) IBOutlet UILabel *lblCategory;
@property (weak, nonatomic) IBOutlet UILabel *lblPlate;
@property (weak, nonatomic) IBOutlet UILabel *lblHour;
@property (weak, nonatomic) IBOutlet UILabel *lblDate;


@end