//
//  main.cpp
//  get_api
//
//  Created by 김대교 on 2020/08/12.
//  Copyright © 2020 김대교. All rights reserved.
//

#include "HttpClient.h"

int main( int argc, char * argv[] )
{
 std::string strUrl, strBodyType, strBody;
 CHttpClient clsClient;
 // 실행 인자에 연동할 HTTP URL 이 포함되어 있다.
 if( argc >= 2 )
 {
  strUrl = argv[1];
 }

 else

 {

   strUrl = http://www.naver.com;

 }



 if( clsClient.DoGet( strUrl.c_str(), strBodyType, strBody ) )
 {
  printf( "BodyType[%s] BodyLen[%d]\n", strBodyType.c_str(), (int)strBody.length() );
  printf( "%s", strBody.c_str() );
 }
 else
 {
  printf( "clsClient.DoGet error\n" );
 }



 return 0;
}
