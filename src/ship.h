/*
 * See Licensing and Copyright notice in naev.h
 */



#ifndef SHIP_H
#  define SHIP_H


#include "opengl.h"
#include "outfit.h"
#include "sound.h"


/* target gfx dimensions */
#define SHIP_TARGET_W   128 /**< Ship target graphic width. */
#define SHIP_TARGET_H   96 /**< Ship target graphic height. */


/**
 * @typedef ShipClass
 *
 * @brief Contains the different types of ships.
 */
typedef enum ShipClass_ {
   SHIP_CLASS_NULL, 
   /* CIVILIAN */
   SHIP_CLASS_CIV_LIGHT,
   SHIP_CLASS_CIV_MEDIUM,
   SHIP_CLASS_CIV_HEAVY,
   /* MILITARY */
   SHIP_CLASS_MIL_LIGHT,
   SHIP_CLASS_MIL_MEDIUM,
   SHIP_CLASS_MIL_HEAVY,
   /* ROBOTIC */
   SHIP_CLASS_ROB_LIGHT,
   SHIP_CLASS_ROB_MEDIUM,
   SHIP_CLASS_ROB_HEAVY,
   /* HYBRID */
   SHIP_CLASS_HYB_LIGHT,
   SHIP_CLASS_HYB_MEDIUM,
   SHIP_CLASS_HYB_HEAVY
} ShipClass;


/*
 * little wrapper for outfits
 */
typedef struct ShipOutfit_ {
   struct ShipOutfit_* next; /* linked list */
   Outfit* data; /* data itself */
   int quantity; /* important difference */
} ShipOutfit;


/*
 * ship class itself
 */
typedef struct Ship_ {

   char* name; /* ship name */
   ShipClass class; /* ship class */

   /* store stuff */
   int price; /* cost to buy */
   int tech; /* see space.h */
   char* fabricator; /* company that makes it */
   char* description; /* selling description */

   /* movement */
   double thrust, turn, speed;

   /* graphics */
   glTexture *gfx_space, *gfx_target;

   /* GUI interface */
   char* gui;

   /* sound */
   int sound;

   /* characteristics */
   int crew;
   int mass;
   int fuel; /* how many jumps by default */

   /* health */
   double armour, armour_regen;
   double shield, shield_regen;
   double energy, energy_regen;

   /* capacity */
   int cap_cargo, cap_weapon; 

   /* outfits */
   ShipOutfit* outfit;

} Ship;


/*
 * load/quit
 */
int ships_load (void);
void ships_free (void);


/*
 * get
 */
Ship* ship_get( const char* name );
char** ship_getTech( int *n, const int* tech, const int techmax );
char* ship_class( Ship* s );
int ship_basePrice( Ship* s );


/*
 * toolkit
 */
void ship_view( char* shipname );


#endif /* SHIP_H */
