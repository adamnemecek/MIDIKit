//
//  MKVirtualDestination.h
//  MIDIKit
//
//  Created by John Heaton on 4/11/14.
//  Copyright (c) 2014 John Heaton. All rights reserved.
//

#import "MKEndpoint.h"
#import "MKClient.h"

// A virtual destination is a client-created endpoint
// that is usable by other clients just like a normal destination.

@protocol MKVirtualDestinationDelegate;
@interface MKVirtualDestination : MKEndpoint <MKClientDependentInstaniation>

// Creates a new virtual destination and adds it to the MIDI server
+ (instancetype)virtualDestinationWithName:(NSString *)name client:(MKClient *)client;
- (instancetype)initWithName:(NSString *)name client:(MKClient *)client;

// Adds a new delegate to be notified when data is received
- (void)addDelegate:(id<MKVirtualDestinationDelegate>)delegate;
- (void)removeDelegate:(id<MKVirtualDestinationDelegate>)delegate;

@end

@protocol MKVirtualDestinationDelegate <NSObject>

// Called when a packet is received
- (void)virtualDestination:(MKVirtualDestination *)virtualDestination
              receivedData:(NSData *)data;

@end
