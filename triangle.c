#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000

/* 
 * Print triangle coordinates along with a message
 */
void print_triangle(triangle_t *triangle, char *msg)
{
    printf("%s: %d,%d - %d,%d - %d,%d\n",
        msg,
        triangle->x1, triangle->y1, 
        triangle->x2, triangle->y2, 
        triangle->x3, triangle->y3);
}

/*
 * Return 0 if triangle coordinates are outside the surface boundary. 1 otherwise.
 */
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    if (triangle->sx1 < 0 || triangle->sx1 >= surface->w ||
        triangle->sx2 < 0 || triangle->sx2 >= surface->w ||
        triangle->sx3 < 0 || triangle->sx3 >= surface->w ||
        triangle->sy1 < 0 || triangle->sy1 >= surface->h ||
        triangle->sy2 < 0 || triangle->sy2 >= surface->h ||
        triangle->sy3 < 0 || triangle->sy3 >= surface->h) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * Scale triangle, altering the on-screen coordinates(e.g. triangle->sx1)
 */
void scale_triangle(triangle_t *triangle)
{
   float scale;
   scale = triangle->scale;             // scale set in teapot -> scale

        triangle->sx1=((float)(triangle->sx1*scale)); // float is used to convert 
        triangle->sx2=((float)(triangle->sx2*scale)); // scale by multiplying cordinates times scale
        triangle->sx3=((float)(triangle->sx3*scale));
        triangle->sy1=((float)(triangle->sy1*scale));
        triangle->sy2=((float)(triangle->sy2*scale));
        triangle->sy1=((float)(triangle->sy1*scale));
    // TODO: Replace the code below with code that scales each triangle coordinate. 
    // The scaling factor is specified in triangle->scale.
    // Remember that this function MUST write to the on-surface coordinates.
    
    
    // draw_triangle

}

/*
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    triangle->tx = 1600/2;          // x-coordinates for screen center
    triangle->ty = 900/2;           // y-coordinates for screen center 
    
    triangle->sx1 = (triangle->tx + triangle->x1);  // This translates the triangle coordinates to screen cordinates. 
    triangle->sx2 = (triangle->tx + triangle->x2);
    triangle->sx3 = (triangle->tx + triangle->x3);
    triangle->sy1 = (triangle->tx + triangle->y1);
    triangle->sy2 = (triangle->tx + triangle->y2);
    triangle->sy3 = (triangle->tx + triangle->y3);

    // TODO: Insert code that moves the triangle on the surface.
    // The translation coordinates are specified in triangle->tx and triangle->ty.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
}

/*
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    int maximum (int a, int b, int c)

    {
        int largest = a;    // Find the highest value of 3 intgers
        if (largest < b)
        {
            largest =b;
        }
        if (largest < c)
        {
            largest = c;
        }
    return largest; 
    }

    int minimum (int a, int b, int c)
    {
        int smallest = a;
        if (b < smallest)
        {
            smallest = b;
        }
        if (c < smallest)
        {
            smallest = c;
        }
    return smallest;        
    }

        

    // TODO: Insert code that calculates the bounding box of a triangle.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
    // The bounding box coordinates should be written to 
    // triangle->rect.x, triangle->rect.y, triangle->rect.w, triangle->rect.h
}

/*
 * Fill the triangle on the surface with the triangle's color
 */
void fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    // TODO: Insert code that fills the triangle with the color specified in triangle->fillcolor.
    // Hint: Draw the triangle with color TRIANGLE_PENCOLOR (this color can not
    // occur in e.g. the teapot or the example triangles).  Thus, if your 
    // approach to filling the triangle relies on looking for the edges of
    // the triangle on the surface (via the GetPixel function), you will find those
    // edges even if the triangle overlaps with a triangle that has already
    // been drawn on the surface.
}

/*
 * Draw a filled triangle on the given surface
 */
void draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    int isOK;

    /* Scale. */
    scale_triangle(triangle);
    
    /* Translate. */
    translate_triangle(triangle);
    
    /* Determine bounding box */
    calculate_triangle_bounding_box(triangle);

    /* Sanity check that triangle is within surface boundaries. */
    isOK = sanity_check_triangle(surface, triangle);
    if (!isOK) {
        print_triangle(triangle, "Triangle outside surface boundaries");
        return;
    }

    /* 
     * TODO: Insert calls to draw_line to draw the triangle.
     * Remember to use the on-surface coordinates (triangle->sx1, etc.)
     */

    /* Fill triangle */
    fill_triangle(surface, triangle);
}
