# Motesque Software Engineer Embedded - Interview Assignment Yocto

## Prerequisites
* Docker Engine
* Yocto Build Host (https://www.yoctoproject.org/docs/2.5.1/brief-yoctoprojectqs/brief-yoctoprojectqs.html)

## Assignment
A colleague of yours implementd a small C++ program using the Eigen Library (http://eigen.tuxfamily.org/index.php?title=Main_Page)
For your convenience, she created a Dockerfile which compiles the program "motesque-eigen" using CMake (https://cmake.org/) 

Your task is to deploy this program on an embedded Linux Distribution based on the Yocto Project. 
Since you do not have the actual hardware, we will use the **qemu** machine target. Please use the **dunfell** branch. 
We will provide you with SSH access to a suitable build-host.


## Acceptance criteria
A tarball file containing the following:
* A new yocto layer "meta-motesque-interview" which contains all necessary files
* The modified local.conf and bblayers.conf file

The image can be run at ~/yocto-interview/poky/build$ runqemu qemux86-64 nographic

The `motesque-eigen` program should be installed in `/usr/local/bin` and produce the following output:
```
Motesque Magic Eigen
  3  -1
2.5 1.5
```

## Tips:
You can  familiarize yourself with the C++ program by using Docker on your local machine:
```
~% docker build -t yocto-interview .
~% docker run --rm yocto-interview motesque-eigen
```

You will need to make changes to the source to get it working in the Yocto image. 
This is common procedure in Yocto and well documented here:
https://wiki.yoctoproject.org/wiki/TipsAndTricks/Patching_the_source_for_a_recipe

