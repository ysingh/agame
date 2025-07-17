#ifndef YS_MATH_H
#define YS_MATH_H

#ifndef SQRTF
#include <math.h>
#define SQRTF sqrtf
#endif

/*
 *  === DATA DEFINITIONS ===
*/

typedef union vec2 {
    struct { float x; float y; };
    float e[2];
} vec2;

typedef union vec3 {
    struct { float x; float y; float z; };
    struct { float r; float g; float b; };
    float e[3];
} vec3;


typedef union vec4 {
    struct { float x; float y; float z; float w; };
    struct { float r; float g; float b; float a; };
    float e[4];
} vec4;

typedef union mat2 {
    struct { 
        float m00; float m01; 
        float m10; float m11; 
    };
    float e[4];
} mat2;

typedef union mat3 {
    struct { 
        float m00; float m01; float m02;
        float m10; float m11; float m12;
        float m20; float m21; float m22;
    };
    float e[9];
} mat3;

typedef union mat4 {
    struct { 
        float m00; float m01; float m02; float m03;
        float m10; float m11; float m12; float m13;
        float m20; float m21; float m22; float m23;
        float m30; float m31; float m32; float m33;
    };
    float e[16];
} mat4;

typedef vec2 point2;
typedef vec3 point3;
typedef vec4 point4;
typedef vec2 color2;
typedef vec3 color3;
typedef vec4 color4;



/*
 * === VEC2 INTERFACE ===
*/
vec2 vec2_add(const vec2 a, const vec2 b);
vec2 vec2_add_s(const vec2 a, const float s);
vec2 vec2_sub(const vec2 a, const vec2 b);
vec2 vec2_sub_s(const vec2 a, const float s);
vec2 vec2_mul(const vec2 a, const vec2 b);
vec2 vec2_mul_s(const vec2 a, const float s);
vec2 vec2_div(const vec2 a, const vec2 b);
vec2 vec2_div_s(const vec2 a, const float s);
float vec2_len_sq(const vec2 a);
float vec2_len(const vec2 a);
vec2 vec2_normal(const vec2 a);
void vec2_normalize(vec2* a);
vec2 vec2_neg(const vec2 a);
void vec2_negate(vec2* a);
float vec2_dot(const vec2 a, const vec2 b);
vec2 vec2_project(const vec2 a, const vec2 b);


/*
 * === VEC3 INTERFACE ===
*/
vec3 vec3_add(const vec3 a, const vec3 b);
vec3 vec3_add_s(const vec3 a, const float s);
vec3 vec3_sub(const vec3 a, const vec3 b);
vec3 vec3_sub_s(const vec3 a, const float s);
vec3 vec3_mul(const vec3 a, const vec3 b);
vec3 vec3_mul_s(const vec3 a, const float s);
vec3 vec3_div(const vec3 a, const vec3 b);
vec3 vec3_div_s(const vec3 a, const float s);
float vec3_len_sq(const vec3 a);
float vec3_len(const vec3 a);
vec3 vec3_normal(const vec3 a);
void vec3_normalize(vec3* a);
vec3 vec3_neg(const vec3 a);
void vec3_negate(vec3* a);
float vec3_dot(const vec3 a, const vec3 b);
vec3 vec3_cross(const vec3 a, const vec3 b);
vec3 vec3_project(const vec3 a, const vec3 b);


/*
 * === VEC4 INTERFACE ===
*/
vec4 vec4_add(const vec4 a, const vec4 b);
vec4 vec4_add_s(const vec4 a, const float s);
vec4 vec4_sub(const vec4 a, const vec4 b);
vec4 vec4_sub_s(const vec4 a, const float s);
vec4 vec4_mul(const vec4 a, const vec4 b);
vec4 vec4_mul_s(const vec4 a, const float s);
vec4 vec4_div(const vec4 a, const vec4 b);
vec4 vec4_div_s(const vec4 a, const float s);
float vec4_len_sq(const vec4 a);
float vec4_len(const vec4 a);
vec4 vec4_normal(const vec4 a);
void vec4_normalize(vec4* a);
vec4 vec4_neg(const vec4 a);
void vec4_negate(vec4* a);
float vec4_dot(const vec4 a, const vec4 b);
vec4 vec4_project(const vec4 a, const vec4 b);


/*
 * === MAT2 INTERFACE ===
*/
inline mat2 mat2_add(const mat2 a, const mat2 b);
inline mat2 mat2_sub(const mat2 a, const mat2 b);
inline mat2 mat2_mul_s(const mat2 a, const float s);
inline mat2 mat2_div_s(const mat2 a, const float s);
inline mat2 mat2_transpose(const mat2 a);
inline mat2 mat2_mul(const mat2 a, const mat2 b);
inline mat2 mat2_div(const mat2 a, const mat2 b);


#ifdef YS_MATH_IMPLEMENTATION


/*
 * ==== VEC2 IMPLEMENTATION =======
*/

inline vec2 vec2_add(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

inline vec2 vec2_add_s(const vec2 a, const float s) {
    vec2 r;
    r.x = a.x + s;
    r.y = a.y + s;
    return r;
}

inline vec2 vec2_sub(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

inline vec2 vec2_sub_s(const vec2 a, const float s) {
    vec2 r;
    r.x = a.x - s;
    r.y = a.y - s;
    return r;
}

inline vec2 vec2_mul(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    return r;
}

inline vec2 vec2_mul_s(const vec2 a, const float s) {
    vec2 r;
    r.x = a.x * s;
    r.y = a.y * s;
    return r;
}

inline vec2 vec2_div(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    return r;
}

inline vec2 vec2_div_s(const vec2 a, const float s) {
    vec2 r;
    float inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    return r;
}

inline float vec2_len_sq(const vec2 a) {
    return a.x * a.x + a.y * a.y; 
}

inline float vec2_len(const vec2 a) {
    return SQRTF(vec2_len_sq(a));
}

inline vec2 vec2_normal(const vec2 a) {
    vec2 r;
    float inv_len = 1.0f/vec2_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    return r;
}

inline void vec2_normalize(vec2* a) {
    float inv_len = 1.0f/vec2_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
}

inline vec2 vec2_neg(const vec2 a) {
    vec2 r;
    r.x = -a.x;
    r.y = -a.y;
    return r;
}

inline void vec2_negate(vec2* a) {
    a->x = -a->x;
    a->y = -a->y;
}

inline float vec2_dot(const vec2 a, const vec2 b) {
    return a.x * b.x + a.y * b.y;
}

inline vec2 vec2_project(const vec2 a, const vec2 b) {
    float dot = vec2_dot(a, b);
    return vec2_mul_s(b, dot/vec2_len_sq(b));
}


/*
 * ==== VEC3 IMPLEMENTATION =======
*/

inline vec3 vec3_add(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline vec3 vec3_add_s(const vec3 a, const float s) {
    vec3 r;
    r.x = a.x + s;
    r.y = a.y + s;
    r.z = a.z + s;
    return r;
}

inline vec3 vec3_sub(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline vec3 vec3_sub_s(const vec3 a, const float s) {
    vec3 r;
    r.x = a.x - s;
    r.y = a.y - s;
    r.z = a.z - s;
    return r;
}

inline vec3 vec3_mul(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    return r;
}

inline vec3 vec3_mul_s(const vec3 a, const float s) {
    vec3 r;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    return r;
}

inline vec3 vec3_div(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    return r;
}

inline vec3 vec3_div_s(const vec3 a, const float s) {
    vec3 r;
    float inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    r.z = a.z * inv_s;
    return r;
}

inline float vec3_len_sq(const vec3 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

inline float vec3_len(const vec3 a) {
    return SQRTF(vec3_len_sq(a));
}

inline vec3 vec3_normal(const vec3 a) {
    vec3 r;
    float inv_len = 1.0f/vec3_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    r.z = a.z * inv_len;
    return r;
}

inline void vec3_normalize(vec3* a) {
    float inv_len = 1.0f/vec3_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
    a->z *= inv_len;
}

inline vec3 vec3_neg(const vec3 a) {
    vec3 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    return r;
}

inline void vec3_negate(vec3* a) {
    a->x = -a->x;
    a->y = -a->y;
    a->z = -a->z;
}

inline float vec3_dot(const vec3 a, const vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec3 vec3_cross(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    return r;
}

inline vec3 vec3_project(const vec3 a, const vec3 b) {
    float dot = vec3_dot(a, b);
    return vec3_mul_s(b, dot/vec3_len_sq(b));
}


/*
 * ==== VEC4 IMPLEMENTATION =======
*/

inline vec4 vec4_add(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

inline vec4 vec4_add_s(const vec4 a, const float s) {
    vec4 r;
    r.x = a.x + s;
    r.y = a.y + s;
    r.z = a.z + s;
    r.w = a.w + s;
    return r;
}

inline vec4 vec4_sub(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
    return r;
}

inline vec4 vec4_sub_s(const vec4 a, const float s) {
    vec4 r;
    r.x = a.x - s;
    r.y = a.y - s;
    r.z = a.z - s;
    r.w = a.w - s;
    return r;
}

inline vec4 vec4_mul(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
    return r;
}

inline vec4 vec4_mul_s(const vec4 a, const float s) {
    vec4 r;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    r.w = a.w * s;
    return r;
}

inline vec4 vec4_div(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    r.w = a.w / b.w;
    return r;
}

inline vec4 vec4_div_s(const vec4 a, const float s) {
    vec4 r;
    float inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    r.z = a.z * inv_s;
    r.w = a.w * inv_s;
    return r;
}

float inline vec4_len_sq(const vec4 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

float inline vec4_len(const vec4 a) {
    return SQRTF(vec4_len_sq(a));
}

inline vec4 vec4_normal(const vec4 a) {
    vec4 r;
    float inv_len = 1.0f/vec4_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    r.z = a.z * inv_len;
    r.w = a.w * inv_len;
    return r;
}

inline void vec4_normalize(vec4* a) {
    float inv_len = 1.0f/vec4_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
    a->z *= inv_len;
    a->w *= inv_len;
}

inline vec4 vec4_neg(const vec4 a) {
    vec4 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    r.w = -a.w;
    return r;
}

inline void vec4_negate(vec4* a) {
    a->x = -a->x;
    a->y = -a->y;
    a->z = -a->z;
    a->w = -a->w;
}

inline float vec4_dot(const vec4 a, const vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline vec4 vec4_project(const vec4 a, const vec4 b) {
    float dot = vec4_dot(a, b);
    return vec4_mul_s(b, dot/vec4_len_sq(b));
}


/*
 * ==== MAT 2 =======
*/

inline mat2 mat2_add(const mat2 a, const mat2 b) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] + b.e[i];
    }
    return r;
}

inline mat2 mat2_sub(const mat2 a, const mat2 b) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] - b.e[i];
    }
    return r;
}

inline mat2 mat2_mul_s(const mat2 a, const float s) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] * s;
    }
    return r;
}

inline mat2 mat2_div_s(const mat2 a, const float s) {
    float inv_s = 1.0f/s;
    return mat2_mul_s(a, inv_s);
}

inline mat2 mat2_transpose(const mat2 a) {
    mat2 r;
    r.m00 = a.m00;
    r.m01 = a.m10;
    r.m10 = a.m01;
    r.m11 = a.m11;
    return r;
}

inline mat2 mat2_mul(const mat2 a, const mat2 b) {
    mat2 r = {};
    return r;

}

inline mat2 mat2_div(const mat2 a, const mat2 b) {
    mat2 r = {};
    return r;
}
/*
 * ==== MAT 3 =======
*/

/*
 * ==== MAT 4 =======
*/
#endif
#endif
