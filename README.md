# ![logo](https://community.trinitycore.org/public/style_images/1_trinitycore.png) TrinityCore

[![Issue Stats](http://www.issuestats.com/github/TrinityCore/TrinityCore/badge/issue)](http://www.issuestats.com/github/TrinityCore/TrinityCore) [![Issue Stats](http://www.issuestats.com/github/TrinityCore/TrinityCore/badge/pr)](http://www.issuestats.com/github/TrinityCore/TrinityCore) [![Bountysource](https://www.bountysource.com/badge/tracker?tracker_id=1310)](https://www.bountysource.com/trackers/1310-trinity-core?utm_source=1310&utm_medium=shield&utm_campaign=TRACKER_BADGE)

## Build Status

6.x | 3.3.5
:------------: | :------------:
[![6.x Build Status](https://travis-ci.org/TrinityCore/TrinityCore.svg?branch=6.x)](https://travis-ci.org/TrinityCore/TrinityCore) | [![3.3.5 Build Status](https://travis-ci.org/TrinityCore/TrinityCore.svg?branch=3.3.5)](https://travis-ci.org/TrinityCore/TrinityCore)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/435/badge.svg)](https://scan.coverity.com/projects/435) | [![Coverity Scan Build Status](https://scan.coverity.com/projects/4656/badge.svg)](https://scan.coverity.com/projects/4656)

## Introduction

TrinityCore is a *MMORPG* Framework based mostly in C++.

It is derived from *MaNGOS*, the *Massive Network Game Object Server*, and is
based on the code of that project with extensive changes over time to optimize,
improve and cleanup the codebase at the same time as improving the in-game
mechanics and functionality.

It is completely open source; community involvement is highly encouraged.

If you wish to contribute ideas or code please visit our site linked below or
make pull requests to our [Github repository](https://github.com/TrinityCore/TrinityCore).

For further information on the TrinityCore project, please visit our project
website at [TrinityCore.org](http://www.trinitycore.org).

## Requirements


Software requirements are available in the [wiki](http://www.trinitycore.info/display/tc/Requirements) for
Windows, Linux and Mac OSX.


## Install

Detailed installation guides are available in the [wiki](http://www.trinitycore.info/display/tc/Installation+Guide) for
Windows, Linux and Mac OSX.

Default versions of OPENSSL & Boost in Ubuntu 16.04+ cause errors with trying to compile and run a server for WoD 6.2.4a. Download the following libraries and put them in a custom library location.
- Boost 1.55 (https://sourceforge.net/projects/boost/files/boost/1.55.0/)
- OpenSSL 1.0.1g (https://ftp.openssl.org/source/old/1.0.1/)

Then execute CMAKE with the following parameters, updated to the installed locations, to setup using these specific verisons.
```
cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=<server directory> -DBOOST_INCLUDEDIR=<boost 1.55 root folder> -DOPENSSL_INCLUDEDIR=<openssl 1.0.1g root folder>
```


## Reporting issues

Issues can be reported via the [Github issue tracker](https://github.com/TrinityCore/TrinityCore/issues?labels=Branch-3.3.5a).

Please take the time to review existing issues before submitting your own to
prevent duplicates.

In addition, thoroughly read through the [issue tracker guide](http://www.trinitycore.org/f/topic/37-the-trinitycore-issuetracker-and-you/) to ensure
your report contains the required information. Incorrect or poorly formed
reports are wasteful and are subject to deletion.


## Submitting fixes

Fixes are submitted as pull requests via Github. For more information on how to
properly submit a pull request, read the [how-to: maintain a remote fork](http://www.trinitycore.org/f/topic/6037-howto-maintain-a-remote-fork-for-pull-requests-tortoisegit/).


## Copyright

License: GPL 2.0

Read file [COPYING](COPYING)


## Authors &amp; Contributors

Read file [THANKS](THANKS)


## Links

[Site](http://www.trinitycore.org)

[Wiki](http://trinitycore.info)

[Documentation](http://www.trinitycore.net) (powered by Doxygen)

[Forums](http://www.trinitycore.org/f/)
