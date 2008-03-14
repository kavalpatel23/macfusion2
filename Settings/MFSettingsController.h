//
//  MFSettingsController.h
//  MacFusion2
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Cocoa/Cocoa.h>
#import "MFClientFSDelegateProtocol.h"

@class MFClient, MFClientFS, MFFilesystemTableView, MFPreferencesController;


@interface MFSettingsController : NSObject <MFClientFSDelegateProtocol> {
	IBOutlet NSArrayController* filesystemArrayController;
	IBOutlet NSArrayController* pluginArrayController;
	IBOutlet MFFilesystemTableView* filesystemTableView;
	IBOutlet NSBox* configurationViewBox;
	IBOutlet NSPopUpButton* button;
	IBOutlet NSButton* mountButton;
	
	NSMutableDictionary* filesystemConfigurationViewControllers;
	MFClient* client;
	MFClientFS* fsBeingEdited;
	MFPreferencesController* preferencesController;
	
	BOOL creatingNewFS;
}

- (IBAction)popupButtonClicked:(id)sender;
- (IBAction)showPreferences:(id)sender;
- (IBAction)startMenuItem:(id)sender;

- (void)editFilesystem:(MFClientFS*)fs;
- (void)deleteFilesystem:(MFClientFS*)fs;
- (void)toggleMountOnFilesystem:(MFClientFS*)fs;


@property(readonly) MFClient* client;
@end