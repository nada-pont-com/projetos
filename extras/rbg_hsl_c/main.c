#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double max(double numb1, double numb2){
    return numb1>numb2 ? numb1 : numb2;
}

double min(double numb1, double numb2){
    return numb1<numb2 ? numb1 : numb2;
}

double mod(double numb){
    return numb<0 ? numb*-1 : numb;
}

double* rgb_to_hsl(double  r,double g,double b){
    double R,G,B;
    R = r/255;
    G = g/255;
    B = b/255;
    double cMax = max(max(B,G),R);
    double cMin = min(min(B,G),R);
    double delta = cMax-cMin;
    double h = 0,l = 0,s = 0;

    l = (cMax+cMin)/2;
    
    if(delta==0){
        h = 0;
    }else if (cMax==R){
        h = 60*( ( (G-B) /delta) );
    }else if(cMax==B){
        h = 60*( ((B-R) /delta) + 2 );
    }else if(cMax==G){
        h = 60*( ((R-G) /delta) + 4 );
    }

    if(delta!=0){
        s = delta/ (1 - mod(2*l -1));
    }

    printf("Red:%.2f Green:%.2f Blue:%.2f\n",r,g,b);
    printf("delta:%.2f Max:%.2f Min:%.2f\n",delta,cMax,cMin);
    printf("H:%.2f L:%.2f S:%.2f\n",h,l,s);
    double* hsl = calloc(3,sizeof(double));
    hsl[0] = h;
    hsl[1] = s;
    hsl[2] = l;

    return hsl;
}

double* hsl_to_rgb(double h,double s,double l){
    double c = (1 - mod(2*l-1)) * s;
    double x = c * (1 - mod( ( (int) (h/60) % 2) -1));
    double m = l - (c/2);
    double* rgb = calloc(3,sizeof(double));

    if(0<=h<60){
        rgb[0] = c;
        rgb[1] = x;
        rgb[2] = 0;
    }else if (60<=h<120){
        rgb[0] = x;
        rgb[1] = c;
        rgb[2] = 0;
    }else if (120<=h<180){
        rgb[0] = 0;
        rgb[1] = c;
        rgb[2] = x;
    }else if (180<=h<240){
        rgb[0] = 0;
        rgb[1] = x;
        rgb[2] = c;
    }else if (240<=h<300){
        rgb[0] = x;
        rgb[1] = 0;
        rgb[2] = c;
    }else if (300<=h<360){
        rgb[0] = c;
        rgb[1] = 0;
        rgb[2] = x;
    }

    for (int i = 0; i < 3; i++){
        rgb[i] = (rgb[i]+m)*255;
    }
    
    return rgb;
}

void main(){
    double r = 60,g = 20,b = 5;
    double* hsl = rgb_to_hsl(r,g,b);
    double* rgb = hsl_to_rgb(hsl[0],hsl[1],hsl[2]);
    printf("Red:%.2f Green:%.2f Blue:%.2f\n",rgb[0],rgb[1],rgb[2]);
}
