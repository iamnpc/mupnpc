#import "DLNAController.h"

#import "CGUpnpAvObject.h"
#import "CGUpnpAvContainer.h"

@implementation DLNAController

- (id)init
{
	if ((self = [super init]) == nil)
		return nil;
		
	dmc = [[CGUpnpAvController alloc] init];
	if (!dmc)
		return nil;
		
	return self;
}

- (void)dealloc
{
	[dmc release];
	[super dealloc];
}

- (void)finalize
{
	[dmc release];
	[super finalize];
}

- (IBAction)searchDMS:(id)sender 
{
	if (dmc)
		[dmc search];
	NSWindow *mainWin = [NSApp mainWindow];
	if (mainWin == nil)
		return;
	[mainWin update];
}

- (NSInteger)browser:(NSBrowser *)sender numberOfRowsInColumn:(NSInteger)column
{		
	if (column == 0) {
		NSArray *serverArray = [dmc servers];
		if ([serverArray count] <= 0) {
			[dmc search];
			serverArray = [dmc servers];
		}
		return [serverArray count];
	}

	NSString *path = [sender pathToColumn:column];
	NSArray *avObjs = [dmc browseWithTitlePath:path];
	if (avObjs == nil)
		return 0;
	return [avObjs count];
}

- (void)browser:(NSBrowser *)sender willDisplayCell:(id)cell atRow:(NSInteger)row column:(NSInteger)column
{
	if (column == 0) {
		NSArray *serverArray = [dmc servers];
		if (row < [serverArray count]) {
			CGUpnpAvServer *server = [serverArray objectAtIndex:row];
			[cell setTitle:[server friendlyName]];
			[cell setLeaf:NO];
		}
	}

	NSString *path = [sender pathToColumn:column];
	CGUpnpAvObject *avObj = [dmc objectForTitlePath:path];
	if (avObj == nil)
		return;
	if (![avObj isContainer])
		return;
	CGUpnpAvContainer *avCon = (CGUpnpAvContainer *)avObj;
	for (CGUpnpAvObject *childObj in [avCon children]) {
		[cell setTitle:[childObj title]];
		if (childObj.isContainer)
			[cell setLeaf:NO];
		else if (childObj.isItem)
			[cell setLeaf:YES];
	}
}

@end