//
//  SPMySQLConnectionProxy.h
//  SPMySQLFramework
//
//  Created by Stuart Connolly (stuconnolly.com) on July 2, 2009.
//  Copyright (c) 2009 Stuart Connolly. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//
//  More info at <https://github.com/sequelpro/sequelpro>


/**
 * Connection proxy state constants.
 */
typedef enum {
	SPMySQLProxyIdle				= 0,
	SPMySQLProxyConnecting			= 1,
	SPMySQLProxyWaitingForAuth		= 2,
	SPMySQLProxyConnected			= 3,
	SPMySQLProxyForwardingFailed	= 4
} SPMySQLConnectionProxyState;


@protocol SPMySQLConnectionProxy <NSObject>

/**
 * All the methods for this protocol are required.
 */

/**
 * Connect the proxy.
 */
- (void)connect;

/**
 * Disconnect the proxy.
 */
- (void)disconnect;

/**
 * Get the current state of the proxy.
 */
- (SPMySQLConnectionProxyState)state;

/**
 * Get the local port being provided by the proxy.
 */ 
- (NSUInteger)localPort;

/**
 * Sets the method the proxy should call whenever the state of the connection changes.
 */
- (BOOL)setConnectionStateChangeSelector:(SEL)theStateChangeSelector delegate:(id)theDelegate;

@end
