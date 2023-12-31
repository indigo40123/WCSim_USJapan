#include <stdio.h>

//--------------------------------------------------------------
//private

// *************************************************************
// * tests, if a point is inside the allowed fitting volume    *
// *************************************************************
inline int searchgrid::fit_volume(double px,double py,double pz)
{
  if (pz<-zmax) return(0);    // return 0, if z<-zmax
  if (pz>zmax) return(0);     // return 0, if z>+zmax
  return(px*px+py*py<=rmax2); // return 0, if r^2>rmax^2
}

//--------------------------------------------------------------
//protected

// *************************************************************
// * add a point, if inside the allowed fitting volume         *
// *************************************************************
inline void searchgrid::add_point(double px,double py,double pz)
{
  if (fit_volume(px,py,pz))  // if inside allowed cylinder, store point
    {
      points[3*npoint]=px;   // x-coordinate
      points[3*npoint+1]=py; // y-coordinate
      points[3*npoint+2]=pz; // z-coordinate
      mult[npoint++]=1;      // only one point is `averaged'
    }
}

// *************************************************************
// * increase the size of the point array                      *
// *************************************************************
inline void searchgrid::expand_size(int addsize)
{
  if (npoint==0)     // simple, if there is no point stored, yet
    {
       if (mpoint!=0) // delete arrays, if necessary
        {
	  delete points;
	  delete mult;
	}
      mpoint=addsize; // create new arrays of size addsize
      mult=new int[mpoint];
      points=new double[3*mpoint];
      return;         // quit
    }

  // copy pointers
  int *save_mult=mult,sec;
  double    *save_points=points;

  // create larger arrays, copy old arrays, then delete old arrays
  mpoint+=addsize;
  mult=new int[mpoint];
  for(sec=0; sec<npoint; sec++)
    mult[sec]=save_mult[sec];
  delete save_mult;
  points=new double[3*mpoint];
  for(sec=0; sec<3*npoint; sec++)
    points[sec]=save_points[sec];
  delete save_points;
}

//--------------------------------------------------------------
//public

// *************************************************************
// * create empty grid                                         *
// *************************************************************
inline searchgrid::searchgrid(double r,double z,double dwall)
{
  nsparse=npoint=mpoint=0; // no points and no average sets
  rmax=r-dwall;            // define maximum allowed radius
  zmax=z-dwall;            // define maximum allowed |z|
  rmax2=rmax*rmax;         // calculate maximum allowed radius^2
}

// *************************************************************
// * destroy grid                                              *
// *************************************************************
inline searchgrid::~searchgrid(void)
{
  if (mpoint>0)  // if the point arrays were created, delete them
    {
      delete mult;
      delete points;
      npoint=mpoint=0;
    }
  if (nsparse>0) // if there are average sets, delete start indices
    delete set_starts;
}

// *************************************************************
// * close current set of points and start a new set           *
// *************************************************************
inline void searchgrid::close(void)
{
  if (nsparse==0) // create a new array for set starting indices
    {
      set_starts=new int[1];
      set_starts[0]=npoint;
      nsparse=1;
      return;
    }
  else            // expand an existing array
    {
      int *save_starts=set_starts,point;

      set_starts=new int[nsparse+1];
      for(point=0; point<nsparse; point++)
	set_starts[point]=save_starts[point];
      delete save_starts;
      set_starts[nsparse]=npoint;
      nsparse++;
    }
}

// *************************************************************
// * return number of grid point sets                          *
// *************************************************************
inline int searchgrid::nset(void)
{
  return(nsparse);
}

// *************************************************************
// * return size of a set of grid points                       *
// *************************************************************
inline int searchgrid::size(int set)
{
  if (nsparse==0)                   // if no average sets,
    {
      if (set<=0) return(npoint);   // return number of unaveraged points
      return(-1);                   // or -1
    }
  if (set>nsparse) return(-1);      // invalid set
  if (npoint==0) return(0);         // if no points, return 0
  if (set==0) return(set_starts[0]);// number of points is in set_starts[0]
  if ((set<0) || (set==nsparse))    // set number<0 means last set
    return(npoint-set_starts[nsparse-1]);
  // number of points is start index of set minus start index of previous set
  return(set_starts[set]-set_starts[set-1]);
}

// *************************************************************
// * copy a set of grid points to an array p of dimension dim  *
// * with an offset offx (x-coordinate), offy (y-coordinate)   *
// * and offz (z-coordinate)                                   *
// *************************************************************
inline void searchgrid::copy_points(int set,float *p,int dim,
                                    int offx,int offy,int offz)
{
  if (set>nsparse) return; // quit, if invalid set

  int loop;

  if (nsparse==0)          // if no average sets,
    {
      if (set>0) return;   // set doesn't exist
      for(loop=0; loop<npoint; loop++,p+=dim)
        { // increment array pointer by dimension dim
          p[offx]=points[3*loop];
          p[offy]=points[3*loop+1];
          p[offz]=points[3*loop+2];
        }
      return;
    }
  if (set==0)              // number of points is in set_starts[0]
    for(loop=0; loop<set_starts[0]; loop++,p+=dim)
      { // increment array pointer by dimension dim
        p[offx]=points[3*loop];
        p[offy]=points[3*loop+1];
        p[offz]=points[3*loop+2];
      }
  else                    // last set
    if ((set<0) || (set==nsparse))
      for(loop=set_starts[nsparse-1]; loop<npoint; loop++,p+=dim)
        { // increment array pointer by dimension dim
	  p[offx]=points[3*loop];
	  p[offy]=points[3*loop+1];
	  p[offz]=points[3*loop+2];
	}
    else                  // any other set
      for(loop=set_starts[set-1]; loop<set_starts[set]; loop++,p+=dim)
	{ // increment array pointer by dimension dim
	  p[offx]=points[3*loop];
	  p[offy]=points[3*loop+1];
	  p[offz]=points[3*loop+2];
	}
}
