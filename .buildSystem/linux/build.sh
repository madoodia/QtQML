# --------------------- #
# (C) 2020 madoodia.com #
# --------------------- #

# -----= Getting Inputs =---- #
ROOT=$1
FOLDER=$2
export FILE_NAME=$3
export TARGET_NAME=$(basename $ROOT)
# --------------------------- #

# ------= Include Envs =----- #
LINUX_DIR=$(dirname "$0")
. $LINUX_DIR/envVars.sh
# --------------------------- #

# ------- Using G++9 ------ #
export CC=/opt/rh/devtoolset-9/root/usr/bin/gcc
export CXX=/opt/rh/devtoolset-9/root/usr/bin/g++

# --------- Common ---------- #
cd $ROOT
if [ -d build ]; then
    rm -rf build*
fi
if [ -f "$ROOT/$FOLDER/$FOLDER" ]; then
    rm -rf $ROOT/$FOLDER/$FOLDER
fi
mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$EXTRA_PREFIX_PATH $ROOT/$FOLDER
cmake --build .

# ----= Folder Project =----- #
# -----= File Project =------ #
# --------- Release --------- #
if [ "$FOLDER" != "." ]; then
    cp $FOLDER $ROOT/$FOLDER
fi
# --------------------------- #

# ---= Running EXE File =---- #
cd $ROOT
if [ -f $ROOT/$FOLDER/$FOLDER ]; then
    ./$FOLDER/$FOLDER
    # ./$TARGET_NAME --gtest_output="xml:./$TARGET_NAME.xml"
fi

# --------------------------- #
