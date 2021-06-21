# DUNEprotoTKI: tools for TKI analyses on protoDUNE data
  ## Tags
  20200716_DUNEproto_selection: version used to produce                       https://indico.fnal.gov/event/44473/contributions/191740/attachments/131455/160976/20200716_DUNEproto_selection_xlu.pdf 
  
  ## Documentation of source codes 
   http://www-pnp.physics.ox.ac.uk/~luxi/transport/doxygen/DUNEprotoTKI

  ## Analysis Tutorial
   https://docs.google.com/document/d/1WtcmMc4_-jgkhw0bKZWe98nhYL54orRb7lmLkx6MgzQ/edit?usp=sharing
  
  ## Quick how-to
0. First checkout TKI package in some location $TKI_PARENT
   ```
   cd $TKI_PARENT
   git clone https://github.com/luxianguo/TKI.git
   ```
   Then checkout DUNEprotoTKI package in some other location $DUNEPROTOTKI_PARENT
   ```
   cd $DUNEPROTOTKI_PARENT
   git clone https://github.com/luxianguo/DUNEprotoTKI.git
   ```
   style/, bin/, and include/AnaFunctions.h are from TKI. Need to link it to DUNEprotoTKI/
   ```
   cd $DUNEPROTOTKI_PARENT/DUNEprotoTKI
   ln -s $TKI_PARENT/TKI
   ```
1. The symbolic links in 
   ```
   anaData/input/
   ```
   need to be unlinked (unlink) and then relinked (ln -s) to the actual paths of the data. 
   - keep the old link name by using 
   ```
   ln -s actual_path old_link_name
   ```
   otherwise the input will break.
   - ***Do not push root files to repository.***
   - Printouts of the data structure can be found in doc/.

2. Setup ROOT and then do
   ```
   cd $DUNEPROTOTKI_PARENT/DUNEprotoTKI
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





