//
//  GMException.h
//  Game Framework
//
//  Created by numata on Jan 03, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#ifndef __GM_EXCEPTION_H__
#define __GM_EXCEPTION_H__


#include "GMObject.h"
#include <exception>
#include <string>


/*!
    @class  GMException
    @group  Error Handling
    Karakuri2 で発生するすべての例外の親クラスです。
 */
class GMException : public std::exception, public GMObject {

protected:
    std::string     mMessage;
    
public:
    GMException() throw();
    GMException(const char* format, ...) throw();
    GMException(const std::string& message) throw();
    virtual ~GMException() throw();
    
public:
    virtual std::string getExceptionClassName() const;
    virtual const char* what() const throw();
    
};

/*!
    @class  GMArithmeticException
    @group  Error Handling
    数値計算時に発生する例外です。
 */
class GMArithmeticException : public GMException {

public:
    GMArithmeticException() throw();
    GMArithmeticException(const char* format, ...) throw();
    GMArithmeticException(const std::string& message) throw();    
    
public:
    virtual std::string getExceptionClassName() const { return "GMArithmeticException"; }

};


/*!
    @class  GMInvalidOperationException
    @group  Error Handling
    不正な操作が行われた時に発生する例外です。
 */
class GMInvalidOperationException : public GMException {
    
public:
    GMInvalidOperationException() throw();
    GMInvalidOperationException(const char* format, ...) throw();
    GMInvalidOperationException(const std::string& message) throw();    
    
public:
    virtual std::string getExceptionClassName() const { return "GMInvalidOperationException"; }
    
};


/*!
    @class  GMOutOfMemoryException
    @group  Error Handling
    メモリの不足時に発生する例外です。
 */
class GMOutOfMemoryException : public GMException {
    
public:
    GMOutOfMemoryException() throw();
    GMOutOfMemoryException(const char* format, ...) throw();
    GMOutOfMemoryException(const std::string& message) throw();    
    
public:
    virtual std::string getExceptionClassName() const { return "GMOutOfMemoryException"; }
    
};


#endif  //#ifndef __GM_EXCEPTION_H__


