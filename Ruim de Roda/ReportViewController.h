//
//  ReportViewController.h
//  Ruim de Roda
//
//  Created by Matheus Frozzi Alberton on 11/04/15.
//  Copyright (c) 2015 Ruim de Roda. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>

#define METERS_MILE 109.344
#define METERS_FEET 3.28084

@interface ReportViewController : UIViewController <UIApplicationDelegate,CLLocationManagerDelegate,MKMapViewDelegate,UITextFieldDelegate>

@property UIImage *imageReport;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (weak, nonatomic) IBOutlet UIView *postingVIew;

@property (weak, nonatomic) IBOutlet UIImageView *reportImage;
@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (weak, nonatomic) IBOutlet UILabel *addressLabel;
@property (weak, nonatomic) IBOutlet UILabel *categoryText;
@property (weak, nonatomic) IBOutlet UITextField *plateText;@property UIImage *imageCrop;
@property (weak, nonatomic) IBOutlet UIButton *btnCategory;

@property (nonatomic) UIViewController *sourceVC;

@property NSString *categoryID;
@property NSString *plate;
@property NSString *address;
@property NSString *latitude;
@property NSString *longitude;
@property (strong, nonatomic) CLLocation *initialLocation;

@end
