//
//  ReportManager.m
//  Ruim de Roda
//
//  Created by Henrique Velloso on 4/11/15.
//  Copyright (c) 2015 Ruim de Roda. All rights reserved.
//

#import "ReportManager.h"


@implementation ReportManager

- (void)postReport:(Report *)photo photoImage:(UIImage *)photoImage response:(void (^)(BOOL success, NSError *error))response {
    
    
    
}

- (void)requestReports:(void (^)(NSArray *resultReports, NSError *error))response {
    
    PFQuery *query = [PFQuery queryWithClassName:@"Report"];

    [query includeKey:@"Category"];
    [query orderByAscending:@"createdAt"];
    
    
    [query findObjectsInBackgroundWithBlock:^(NSArray *resultReports, NSError *error) {
        
        
        if (!resultReports) {
            response(nil, error);
        }
        else {
            NSMutableArray *reports = [[NSMutableArray alloc] init];
            
            for (PFObject *resultReport in resultReports)
            {
                
                Report *report = [[Report alloc] init];
                
                report.objectId = resultReport.objectId;
                report.address = [resultReport objectForKey:@"address"];
                report.latitude = [resultReport objectForKey:@"latitude"];
                report.longitude = [resultReport objectForKey:@"longitude"];
                report.plate = [resultReport objectForKey:@"plate"];
                report.createdAt = resultReport.createdAt;
                report.updatedAt = resultReport.updatedAt;
                
                //Category
                CategoryReport *category = [[CategoryReport alloc] init];
                PFObject *pfCategory = resultReport[@"Category"];
                
                category.objectId = pfCategory.objectId;
                category.text = [pfCategory objectForKey:@"text"];
                category.createdAt = pfCategory.createdAt;
                category.updatedAt = pfCategory.updatedAt;
                
                report.category = category;
                
                
                //Photo
                if ([resultReport objectForKey:@"photo"])
                {
                    PFFile *pfFile = [resultReport objectForKey:@"photo"];
                    report.photo = pfFile.url;
                }
                
                
                [reports addObject:report];
                
            }
            
            response([reports copy], nil);
        }
    }];
    
}

@end