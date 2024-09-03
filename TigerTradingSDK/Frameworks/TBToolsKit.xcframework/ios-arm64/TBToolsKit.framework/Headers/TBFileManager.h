//
//  TBFileManager.h
//  Stock
//
//  Created by liwt on 15/1/8.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBFileManager : NSObject {
    
}

// check whether exists the directory ,if not,create one
+ (void) checkDirectory:(NSString *)strDir;

// check whether exists the file
+ (bool) checkFileExists:(NSString *)dir fileName:(NSString *)fileName;
+ (bool) checkFileExists:(NSString *)filePath;

// remove a file
+ (bool) deleteFile:(NSString *)filePath;

// copy a file
+ (bool) copyFileAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;

// returns an NSArray of NSStrings representing the filenames of the items in the directory
+ (NSArray *)contentsOfDirectoryAtPath:(NSString *)path error:(NSError **)error;

// return the Document directory of the bundle
+ (NSString *) getDocumentDir;
+ (NSString *) getLibraryCacheDir;
+ (NSString *) getLibraryDir;
+ (NSString *)getApplicationSupportDir;
+ (NSString *) getResourceDir;

+ (NSURL *) getFileBaseURL;

+ (NSString *) createDirectoryPath:(NSString *)path direName:(NSString *)dirName;

// Download url content and save to a file, usually some small files, like img, xml, etc
// This operation is synchronise and will block current thread, so use it carefully.
+ (bool) syncDownloadFile:(NSString *)urlStr localDir:(NSString *)localDir fileName:(NSString *)fileName;

@end