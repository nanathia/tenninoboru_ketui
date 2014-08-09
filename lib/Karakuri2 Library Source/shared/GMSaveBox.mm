//
//  GMSaveBox.mm
//  Game Framework
//
//  Created by numata on 09/07/25.
//  Copyright 2009-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#import "GMSaveBox.h"

#import <Foundation/Foundation.h>


#pragma mark -
#pragma mark コンストラクタ、デストラクタ

GMSaveBox::GMSaveBox()
{
    // Do nothing
}

GMSaveBox::~GMSaveBox()
{
    // Do nothing
}


#pragma mark -
#pragma mark 値が設定されていることの確認と、保存の実行
bool GMSaveBox::HasValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    bool ret = ([defaults objectForKey:keyStr] != nil)? true: false;
    
    [keyStr release];
    [keyStrData release];
    
    return ret;
}

void GMSaveBox::RemoveValue(const std::string& key) const
{
    NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];

    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    if ([defaults objectForKey:keyStr]) {
        [defaults removeObjectForKey:keyStr];
    }

    [keyStr release];
    [keyStrData release];
}

void GMSaveBox::Save()
{
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults synchronize];
}


#pragma mark -
#pragma mark 値の取得

bool GMSaveBox::GetBoolValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    bool ret = [defaults boolForKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
    
    return ret;
}

double GMSaveBox::GetDoubleValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    double ret = [[defaults objectForKey:keyStr] doubleValue];
    
    [keyStr release];
    [keyStrData release];
    
    return ret;
}

float GMSaveBox::GetFloatValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    float ret = [defaults floatForKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
    
    return ret;
}

int GMSaveBox::GetIntValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    int ret = (int)[defaults integerForKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
    
    return ret;
}

std::string GMSaveBox::GetStringValue(const std::string& key) const
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    NSString* retObj = [defaults stringForKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
    
    if (!retObj) {
        return "";
    }
    
    return std::string([retObj cStringUsingEncoding:NSUTF8StringEncoding]);
}


#pragma mark -
#pragma mark 値の設定

void GMSaveBox::SetBoolValue(const std::string& key, bool boolValue)
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setBool:boolValue forKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
}

void GMSaveBox::SetDoubleValue(const std::string& key, double doubleValue)
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:[NSNumber numberWithDouble:doubleValue] forKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
}

void GMSaveBox::SetFloatValue(const std::string& key, float floatValue)
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setFloat:floatValue forKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
}

void GMSaveBox::SetIntValue(const std::string& key, int intValue)
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setInteger:intValue forKey:keyStr];
    
    [keyStr release];
    [keyStrData release];
}

void GMSaveBox::SetStringValue(const std::string& key, const std::string &strValue)
{
	NSData* keyStrData = [[NSData alloc] initWithBytes:key.data() length:key.length()];
    NSString* keyStr = [[NSString alloc] initWithData:keyStrData encoding:NSUTF8StringEncoding];
    
	NSData* valueStrData = [[NSData alloc] initWithBytes:strValue.data() length:strValue.length()];
    NSString* valueStr = [[NSString alloc] initWithData:valueStrData encoding:NSUTF8StringEncoding];
    
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:valueStr forKey:keyStr];
    
    [valueStr release];
    [valueStrData release];
    
    [keyStr release];
    [keyStrData release];
}


#pragma mark -
#pragma mark デバッグ文字列の作成

std::string GMSaveBox::to_s() const
{
    return "<savebox>()";
}


