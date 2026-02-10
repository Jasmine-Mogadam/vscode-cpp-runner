#pragma once
#include <string>
#include <functional>
typedef int (* myFunc )(std:: string );
typedef std:: function <int (std:: string )> 
functionlMyFunc ;
void setMyFunc ( myFunc my);
void setMyFunc2( functionlMyFunc
myFunctionlMyFunc );
int SomeLowLevelFunc ();