# BONSAI
Low Energy reconstruction code

## How to compile
* Set the environment variable `$ROOTSYS` to point to your ROOT install
* Set the environment variable `$WCSIMDIR` to point to your WCSim install
* Set the environment variable `$BONSAIDIR` to point to this directory
* Run `make`
  * This will produce `libWCSimBonsai.so` in `$BONSAIDIR`

## How to run
* `$BONSAIDIR/data/like.bin` should be replaced for each geometry configure.
  * Default `like.bin` is `HK_2020_20percentBL.bin` (HK 20% B&L coverage, ID 70.8 x 54.8 m)
  * Other files exist in `$BONSAIDIR/data/likelihood_binary/`
    | Filename     | Description |
    | ------------ | ----------- |
    | HK_2020_20percentBL.bin | HK 20% B&L coverage, ID 70.8 x 54.8 m |
    | Cyl100.bin   | 100m cylinder with 20" B&L PMT |
    | Cyl80.bin    | 80m cylinder with 20" B&L PMT |
    | Cyl60.bin    | 60m cylinder with 20" B&L PMT |
    | HK20PMT.bin  | Egg-shaped HK with 20" Normal PMT |
    | HK20BL.bin   | Egg-shaped HK with 20" B&L PMT |
    | SK20BL.bin   | Super-K detector with 20" B&L PMT |
    | SK12BL.bin   | Super-K detector with 12" B&L PMT |
    | SK20PMT.bin  | Super-K detector with 20" Normal PMT (SK-I ~ IV configure.) |
  * You can also make your own tune using the instructions in `$BONSAIDIR/data/tuning`
* Run `$BONSAIRDIR/sample-root-scripts/sample_bonsai.C` on your WCSim output
  * It is recommended to use `$BONSAIDIR/rootbonsai` (a root wrapper) to run scripts in compiled mode.
    `rootbonsai` automatically handles telling ROOT of libs and incs

## The important part of the code
* WCSimBonsai is the main class. It reads in geometry information, and calls reconstruction functions.
  It should be run by calling two methods
  * `Init(WCSimRootGeom*)`
    * Sets up all the variables, and geometry
    * Run once per file
  * `BonsaiFit(float *vert, float *result, float *maxlike, int *nsel, int *nhit, int *cab, float *t, float *q)`
    * `float * vert`
      * OUTPUT: Reconstructed vertex (x,y,z,t)
    * `float * result`
      * OUTPUT: Reconstructed direction (as Euler angles) and Cherenkov cone: theta (zenith), phi (azimuth), alpha, cos(Cherenkov angle), ellipticity, likelihood
    * `float * maxlike`
      * OUTPUT: [1] is goodness of time fit (i.e. of vert[3]), [2] is goodness of fit
    * `int * nsel`
      * ?
    * `int * nhit`
      * INPUT: Number of hits
    * `int * cab`
      * INPUT: List of hit tube IDs. Length = number of hits
    * `float * t`
      * INPUT: List of hit times. Length = number of hits
    * `float * q`
      * INPUT: List of hit charges. Length = number of hits
    * Run once per trigger
