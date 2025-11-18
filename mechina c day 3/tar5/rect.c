#include<stdio.h>

struct cord
{
    float x;
    float y;
};

struct rect
{
    struct cord top_left;
    struct cord bottom_right;
};

float area(struct rect r){
    int width = r.top_left.x - r.bottom_right.x;
    int height = r.bottom_right.y - r.top_left.y;
    return width * height;
}

int main(){
    struct rect r;
    printf("Enter top left coordinates: ");
    scanf("%f,%f" , &r.top_left.x, &r.top_left.y);

    printf("Enter bottom right coordinates: ");
    scanf("%f,%f" , &r.bottom_right.x, &r.bottom_right.y);

    printf("Area: %f\n", area(r));
    return 0;
}
