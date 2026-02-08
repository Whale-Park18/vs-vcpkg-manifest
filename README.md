# vcpkg Manifest Mode(Visual Studio)

vcpkg에는 클래식, 매니페스트 두 가지 모드가 있습니다. 매니페스트 모드는 프로젝트별 종속성을 선언하고 관리하는 데 사용됩니다. 이 모드는 `vcpkg.json` 파일을 사용하여 프로젝트의 종속성을 정의합니다.

## vcpkg 매니페스트 만들기(`vcpkg.json`)
프로젝트 루트 디렉토리에 `vcpkg.json` 파일을 생성합니다. `dependencies` 필드에 필요한 패키지를 나열합니다.
```json
{
  "dependencies": [
	"spdlog",
	"icu"
  ]
}
```

## 빌드 시스템과 vcpkg 통합
빌드 시스템(Visual Studio)과 vcpkg를 통합하여 종속성을 자동으로 설치하고 관리할 수 있습니다.
```bash
vcpkg integrate install
```
위 명령을 실행하면, 빌드 시스템이 vcpkg를 인식하여 종속성을 자동으로 설치합니다. 설치된 모든 패키지는 `vcpkg_installed` 디렉터리에 설치됩니다.

## 프로젝트 빌드
기본적으로 Visual Studio는 매니페스트 모드를 사용하지 않도록 설정되어있습니다. 매니페스트 모드를 사용하려면 **프로젝트 설정 > 구성 속성 > vcpkg > Use Vcpkg Manifest** 항목을 **예**로 설정합니다.
![Visual Studio에서 vcpkg 매니페스트 설정](https://learn.microsoft.com/ko-kr/vcpkg/resources/vs-enable-vcpkg-manifest.png)

이제 프로젝트를 빌드하면, vcpkg가 `vcpkg.json` 파일을 읽고 필요한 종속성을 자동으로 설치합니다.
```bash
1>------ 빌드 시작: 프로젝트: vcpkg-manifest, 구성: Debug x64 ------
1>  Installing vcpkg dependencies to D:\workspace\vcpkg-manifest\vcpkg-manifest\vcpkg_installed\x64-windows\
1>  "C:\develop\vcpkg\vcpkg.exe" install  --x-wait-for-lock --triplet "x64-windows" --vcpkg-root "C:\develop\vcpkg\\" "--x-manifest-root=D:\workspace\vcpkg-manifest\vcpkg-manifest\\" "--x-install-root=D:\workspace\vcpkg-manifest\vcpkg-manifest\vcpkg_installed\x64-windows\\"
1>  삼중항 x64-windows에 대한 컴파일러 해시 감지 중...
1>  컴파일러 찾음: C:/develop/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe
1>  빌드 및 설치할 패키지:
1>    * fmt:x64-windows@11.0.2#1
1>      icu[core,tools]:x64-windows@74.2#6
1>      spdlog:x64-windows@1.15.3
1>    * vcpkg-cmake:x64-windows@2024-04-23
1>    * vcpkg-cmake-config:x64-windows@2024-05-23
1>    * vcpkg-cmake-get-vars:x64-windows@2025-05-29
1>    * vcpkg-make:x64-windows@2025-06-10
1>  이 작업을 완료하기 위해 추가 패키지(*)가 수정됩니다.
1>  1.9 s 후 C:\Users\sowoo\AppData\Local\vcpkg\archives의 패키지 7개를 복원했습니다. 자세한 내용을 보려면 --debug를 사용하세요.
1>  1/7 vcpkg-cmake:x64-windows@2024-04-23을(를) 설치하는 중...
1>  vcpkg-cmake:x64-windows 처리 경과 시간: 25.2 ms
1>  vcpkg-cmake:x64-windows 패키지 ABI: 4dd43499743e15239f3ad08d1d672093c12979575386e1f7a15595c702b20a91
1>  2/7 vcpkg-cmake-get-vars:x64-windows@2025-05-29을(를) 설치하는 중...
1>  vcpkg-cmake-get-vars:x64-windows 처리 경과 시간: 17.3 ms
1>  vcpkg-cmake-get-vars:x64-windows 패키지 ABI: 8c585218a7304183e09a19fdd2872010bad58109cda92308455cdc05f06146aa
1>  3/7 vcpkg-make:x64-windows@2025-06-10을(를) 설치하는 중...
1>  vcpkg-make:x64-windows 처리 경과 시간: 22 ms
1>  vcpkg-make:x64-windows 패키지 ABI: 179b985b67d6fd27130b4cbc496631278157aea5add156078917ae828ca8c069
1>  4/7 icu[core,tools]:x64-windows@74.2#6을(를) 설치하는 중...
1>  icu:x64-windows 처리 경과 시간: 367 ms
1>  icu:x64-windows 패키지 ABI: f0bda28745e08796c9893c3d956fa015502d6091c36baba0164094d3b1dcac53
1>  5/7 vcpkg-cmake-config:x64-windows@2024-05-23을(를) 설치하는 중...
1>  vcpkg-cmake-config:x64-windows 처리 경과 시간: 16.9 ms
1>  vcpkg-cmake-config:x64-windows 패키지 ABI: 6e4c11a10c7e29381ab1b8840b676af6a08a832c1de1b2f0356c8ba551fe5dee
1>  6/7 fmt:x64-windows@11.0.2#1을(를) 설치하는 중...
1>  fmt:x64-windows 처리 경과 시간: 35.3 ms
1>  fmt:x64-windows 패키지 ABI: 528bb8bcc210558f763c35c3a4622fe98b73ff85bfda57a7380ada413514b245
1>  7/7 spdlog:x64-windows@1.15.3을(를) 설치하는 중...
1>  spdlog:x64-windows 처리 경과 시간: 91.1 ms
1>  spdlog:x64-windows 패키지 ABI: 9f39d7120bd851321c6b23e1369027f3c49b54d0e39ec2343685f981947c2075
1>  설치된 콘텐츠에 대한 라이선스는 소유자가 부여합니다. Microsoft는 타사 패키지에 대해 책임을 지지 않으며 라이선스를 부여하지도 않습니다.
1>  일부 패키지에서 SPDX 라이선스를 선언하지 않았습니다. 각 패키지의 'copyright' 파일을 확인하여 라이선스에 대한 자세한 정보를 확인하세요.
1>  이 vcpkg 설치에 설치된 패키지는 다음 라이선스를 선언합니다.
1>  ICU
1>  MIT
1>  icu은(는) pkg-config 모듈을 제공합니다.
1>
1>    # International Components for Unicode: Internationalization library
1>    icu-i18n
1>
1>    # International Components for Unicode: Stream and I/O Library
1>    icu-io
1>
1>    # International Components for Unicode: Common and Data libraries
1>    icu-uc
1>
1>  The package spdlog provides CMake targets:
1>
1>      find_package(spdlog CONFIG REQUIRED)
1>      target_link_libraries(main PRIVATE spdlog::spdlog)
1>
1>      # Or use the header-only version
1>      find_package(spdlog CONFIG REQUIRED)
1>      target_link_libraries(main PRIVATE spdlog::spdlog_header_only)
1>
1>  요청된 모든 설치를 완료했습니다(587 ms).
1>  main.cpp
1>  vcpkg-manifest.vcxproj -> D:\workspace\vcpkg-manifest\x64\Debug\vcpkg-manifest.exe
```

#참고 자료
- [매니페스트 모드란?](https://learn.microsoft.com/ko-kr/vcpkg/concepts/manifest-mode)
- [매니페스트 파일에서 종속성 설치](https://learn.microsoft.com/ko-kr/vcpkg/consume/manifest-mode?tabs=msbuild%2Cbuild-visual-studio)
- [vcpkg.json 참조](https://learn.microsoft.com/ko-kr/vcpkg/reference/vcpkg-json)