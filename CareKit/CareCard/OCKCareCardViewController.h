/*
 Copyright (c) 2016, Apple Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 1.  Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2.  Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 
 3.  Neither the name of the copyright holder(s) nor the names of any contributors
 may be used to endorse or promote products derived from this software without
 specific prior written permission. No license is granted to the trademarks of
 the copyright holders even if such marks are included in this software.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#import <CareKit/CareKit.h>


NS_ASSUME_NONNULL_BEGIN

@class OCKCarePlanStore, OCKCareCardViewController;

/**
 An object that adopts the `OCKCareCardViewControllerDelegate` protocol can use it modify or update the events before they are displayed.
 */
@protocol OCKCareCardViewControllerDelegate <NSObject>

@optional

/**
 Tells the delegate when the a new set of events is fetched from the care plan store.
 
 @param viewController          The view controller providing the callback.
 @param events                  An array containing the fetched set of intervention events.
 */
- (void)careCardViewController:(OCKCareCardViewController *)viewController willDisplayEvents:(NSArray<OCKCarePlanEvent*>*)events;

@end


/**
 The `OCKCareCardViewController` class is a view controller that displays the activities and events
 from an `OCKCarePlanStore` that are of intervention type (see `OCKCarePlanActivityTypeIntervention`).
 
 It includes a master view and a detail view. Therefore, it must be embedded inside a `UINavigationController`.
 */
OCK_CLASS_AVAILABLE
@interface OCKCareCardViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;

/**
 Returns an initialized care card view controller using the specified store.
 
 @param store        A care plan store.
 
 @return An initialized care card view controller.
 */
- (instancetype)initWithCarePlanStore:(OCKCarePlanStore *)store;

/**
 The care plan store that provides the content for the care card.
 
 The care card displays activites and events that are of intervention type (see `OCKCarePlanActivityTypeIntervention`).
 */
@property (nonatomic, readonly) OCKCarePlanStore *store;

/**
 The delegate can be used to modify or update the internvention events before they are displayed.
 
 See the `OCKCareCardViewControllerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<OCKCareCardViewControllerDelegate> delegate;


/**
 The image that will be used to mask the fill shape in the header view.

 In order to provide a custom maskImage, you must have a regular size and small size.
 For example, in the assets catalog, there are "heart" and a "heart-small" assets.
 Both assets must be provided in order to properly render the interface.
 
 If no image is specified, the "heart" image will be loaded from the assets catalog.
 */
@property (nonatomic, null_resettable) UIImage *maskImage;

/**
 The image that will be used to mask the fill shape in the week view.
 
 In order to provide a custom maskImage, you must have a regular size and small size.
 For example, in the assets catalog, there are "heart" and a "heart-small" assets.
 Both assets must be provided in order to properly render the interface.
 
 If no image is specified, the "heart-small" image will be loaded from the assets catalog.
 */
@property (nonatomic, null_resettable) UIImage *smallMaskImage;

/**
 The tint color that will be used to fill the shape.
 
 If tint color is not specified, the OCKRedColor() will be used (see `OCKColors.h`).
 */
@property (nonatomic, null_resettable) UIColor *maskImageTintColor;

@end

NS_ASSUME_NONNULL_END
