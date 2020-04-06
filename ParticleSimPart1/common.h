/*  Antony Adamovich, Dimitra Deliopoulos, Mahmoud Gudarzi
*    common.h for XSEDE hw2 "Particle Simulator" - Serial version
*    West Chester University - CSC 496 - Dr. Lihn B. Ngo
*    Created: 04-MAR-2020 - Last Edited: 05-APR-2020 by Antony Adamovich
*    Please see https://github.com/AAAdamovich/Parallel496
*       for version tracking
*    Definitions
*       Cell: A subdivision of the simulation area, as a square
*       Frontier: An area close a cell's border where particles from 
*       two neighboring cells could potentially interact
*/

#ifndef __CS267_COMMON_H__
#define __CS267_COMMON_H__

inline int min( int a, int b ) { return a < b ? a : b; }
inline int max( int a, int b ) { return a > b ? a : b; }

//
//  saving parameters
//
const int NSTEPS = 1000;
const int SAVEFREQ = 10;
const double CUTOFF = 0.01;
// The max distance between a particle frontier and a cell wall
const double BOUND = CUTOFF * CUTOFF;

//
// particle data structure
//
typedef struct 
{
  double x;
  double y;
  double vx;
  double vy;
  double ax;
  double ay;
} particle_t;

//
//  timing routines
//
double read_timer( );

//
//  simulation routines
//
double set_size( int n );
void init_particles( int n, particle_t *p );
void apply_force( particle_t &particle, particle_t &neighbor , double *dmin, double *davg, int *navg);
void move( particle_t &p );


//
//  I/O routines
//
FILE *open_save( char *filename, int n );
void save( FILE *f, int n, particle_t *p );

//
//  argument processing routines
//
int find_option( int argc, char **argv, const char *option );
int read_int( int argc, char **argv, const char *option, int default_value );
char *read_string( int argc, char **argv, const char *option, char *default_value );

#endif
