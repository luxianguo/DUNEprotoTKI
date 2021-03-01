# DUNEprotoTKI: tools for TKI analyses on protoDUNE data
  ## Tags
  20200716_DUNEproto_selection: version used to produce                       https://indico.fnal.gov/event/44473/contributions/191740/attachments/131455/160976/20200716_DUNEproto_selection_xlu.pdf 
  
  ## Documentation of source codes 
    http://www-pnp.physics.ox.ac.uk/~luxi/transport/doxygen/DUNEprotoTKI

  ## Analysis Tutorial
    https://docs.google.com/document/d/1WtcmMc4_-jgkhw0bKZWe98nhYL54orRb7lmLkx6MgzQ/edit?usp=sharing
  
  ## Quick how-to

0. style/, bin/, and include/AnaFunctions.h are from submodule. Need to load/update separately with
   ```
   git submodule update --init
   ```
   and
   ```
   git submodule update --remote
   ```
   respectively.

   In case of "Permission denied", open .git/config and change the url in [submodule “TKI”] part to url = https://github.com/luxianguo/TKI.git. See https://stackoverflow.com/questions/49191565/git-clone-works-git-submodule-fails-permission-denied

1. The symbolic links in 
   ```
   anaData/input/
   ```
   need to be unlinked (unlink) and then relinked (ln -s) to the actual paths of the data. 
   - ***Do not push root files to repository.***
   - Printouts of the data structure can be found in doc/.

2. Setup ROOT and then do
   ```
   source setup.sh
   ```

3. Go to style/ and compile 
   ```
   ./do.sh
   ```
   - style/ is the lower level tool for all other programs, needed for histogram manipulation.

4. Go to anaData/,
   - and then drawTKI/, drawTracking/ if needed:
     - for truth signal distributions: anaData/ with kTruth=1, followed by drawTKI/
     - for efficiency, momentum resolution, and dEdx: anaData/ with kTruth=1, followed by drawTracking/
     - for event selection: anaData/ with kTruth=0 alone
   - run
     ```
     ./do.sh
     ```
     and all output will be in the ./output/ sub-directories with all printout in see*.log.





