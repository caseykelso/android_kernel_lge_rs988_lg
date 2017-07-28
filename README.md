1. Android build



  - Download original android source code (android-7.0.0_r7) from http://source.android.com

    (

      $repo init -u git://10.168.177.185/platform/manifest.git -b android-7.0.0_r7

      $repo sync -cdq -j12 --no-tags

      $repo start android-7.0.0_r7 --all 

    )



  - Untar opensource packages of RS988_Nougat_Android.tar.gz into downloaded android source directory



    a) tar -xvzf RS988_Nougat_Android.tar.gz



  - And, merge the source into the android source code



  - Run following scripts to build android



    a) source build/envsetup.sh

    b) lunch 1

    c) make -j4



  - When you compile the android source code, you have to add google original prebuilt source(toolchain) into the android directory.

  - After build, you can find output at out/target/product/generic



2. Kernel Build  

  - Uncompress using following command at the android directory



    a) tar -xvzf RS988_Nougat_Kernel.tar.gz



  - When you compile the kernel source code, you have to add google original prebuilt source(toolchain) into the android directory.

  - Run following scripts to build kernel



   - cd android/kernel/msm-3.18

   - make ARCH=arm64 h1_lra_us-perf_defconfig

   - make ARCH=arm64 KERNEL_COMPRESSION_SUFFIX=gz CROSS_COMPILE=../../prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-

	

   - After build, you can find the build image(Image.gz) at arch/arm64/boot
