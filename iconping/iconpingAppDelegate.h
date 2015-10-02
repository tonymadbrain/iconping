//
//  iconpingAppDelegate.h
//  iconping
//
//  Created by Salvatore Sanfilippo on 25/07/11.
//  Copyright 2011 Salvatore Sanfilippo. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface iconpingAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    NSStatusItem *myStatusItem;
    NSImage *onlineIcon, *onlineIconAlternate, *offlineIcon, *offlineIconAlternate;
    NSMenu *myMenu;
    NSMenuItem *statusMenuItem, *openAtStartupMenuItem, *level3MenuItem, *googleMenuItem;
    char* hostToPing;
    uint16_t icmp_id;
    uint16_t icmp_seq;
    int64_t last_received_time;
    int last_rtt;
    int icmp_socket;
    int connection_state;
}

- (void) useLevel3;
- (void) useGoogle;
- (void) changeConnectionState: (int) state;
- (void) showNotification: (NSString*)title message:(NSString*)message;
- (BOOL)loginItemExists;
- (BOOL)toggleLoginItem;

@property (assign) IBOutlet NSWindow *window;
@end

int setSocketNonBlocking(int fd);
int64_t ustime(void);
