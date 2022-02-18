#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Cmdline: sokol-shdc --input data/shaders/ball.glsl --output src/golf/shaders/ball.glsl.h --slang glsl330:glsl300es

    Overview:

        Shader program 'ball':
            Get shader desc: ball_shader_desc(sg_query_backend());
            Vertex shader: ball_vs
                Attribute slots:
                    ATTR_ball_vs_position = 0
                    ATTR_ball_vs_normal = 1
                    ATTR_ball_vs_texture_coord = 2
                Uniform block 'ball_vs_params':
                    C struct: ball_vs_params_t
                    Bind slot: SLOT_ball_vs_params = 0
            Fragment shader: ball_fs
                Uniform block 'ball_fs_params':
                    C struct: ball_fs_params_t
                    Bind slot: SLOT_ball_fs_params = 0
                Image 'ball_normal_map':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_ball_normal_map = 0


    Shader descriptor structs:

        sg_shader ball = sg_make_shader(ball_shader_desc(sg_query_backend()));

    Vertex attribute locations for vertex shader 'ball_vs':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_ball_vs_position] = { ... },
                    [ATTR_ball_vs_normal] = { ... },
                    [ATTR_ball_vs_texture_coord] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]

        SLOT_ball_normal_map = 0;

    Bind slot and C-struct for uniform block 'ball_vs_params':

        ball_vs_params_t ball_vs_params = {
            .proj_view_mat = ...;
            .model_mat = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_ball_vs_params, &SG_RANGE(ball_vs_params));

    Bind slot and C-struct for uniform block 'ball_fs_params':

        ball_fs_params_t ball_fs_params = {
            .color = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_ball_fs_params, &SG_RANGE(ball_fs_params));

*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_ball_vs_position (0)
#define ATTR_ball_vs_normal (1)
#define ATTR_ball_vs_texture_coord (2)
#define SLOT_ball_normal_map (0)
#define SLOT_ball_vs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct ball_vs_params_t {
    mat4 proj_view_mat;
    mat4 model_mat;
} ball_vs_params_t;
#pragma pack(pop)
#define SLOT_ball_fs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct ball_fs_params_t {
    vec4 color;
} ball_fs_params_t;
#pragma pack(pop)
/*
    #version 330
    
    uniform vec4 ball_vs_params[8];
    layout(location = 0) in vec3 position;
    out vec3 frag_normal;
    layout(location = 1) in vec3 normal;
    out vec2 frag_texture_coord;
    layout(location = 2) in vec2 texture_coord;
    
    void main()
    {
        mat4 _27 = mat4(ball_vs_params[4], ball_vs_params[5], ball_vs_params[6], ball_vs_params[7]);
        gl_Position = (mat4(ball_vs_params[0], ball_vs_params[1], ball_vs_params[2], ball_vs_params[3]) * _27) * vec4(position, 1.0);
        frag_normal = normalize((transpose(inverse(_27)) * vec4(normal, 0.0)).xyz);
        frag_texture_coord = texture_coord;
    }
    
*/
static const char ball_vs_source_glsl330[583] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x62,0x61,0x6c,0x6c,0x5f,
    0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x38,0x5d,0x3b,0x0a,0x6c,0x61,
    0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,
    0x30,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x70,0x6f,0x73,0x69,0x74,
    0x69,0x6f,0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,0x20,0x66,0x72,
    0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,
    0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,
    0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,
    0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x6c,0x61,0x79,
    0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x32,
    0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x74,0x65,0x78,0x74,0x75,0x72,
    0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,
    0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x74,0x34,
    0x20,0x5f,0x32,0x37,0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x62,0x61,0x6c,0x6c,
    0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x2c,0x20,0x62,
    0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x35,0x5d,
    0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x36,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x37,0x5d,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,
    0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x28,0x6d,0x61,0x74,0x34,
    0x28,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,
    0x30,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x20,0x2a,0x20,0x5f,
    0x32,0x37,0x29,0x20,0x2a,0x20,0x76,0x65,0x63,0x34,0x28,0x70,0x6f,0x73,0x69,0x74,
    0x69,0x6f,0x6e,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x20,0x3d,0x20,0x6e,0x6f,0x72,
    0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x28,0x74,0x72,0x61,0x6e,0x73,0x70,0x6f,0x73,
    0x65,0x28,0x69,0x6e,0x76,0x65,0x72,0x73,0x65,0x28,0x5f,0x32,0x37,0x29,0x29,0x20,
    0x2a,0x20,0x76,0x65,0x63,0x34,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x2c,0x20,0x30,
    0x2e,0x30,0x29,0x29,0x2e,0x78,0x79,0x7a,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,
    0x64,0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,
    0x64,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 330
    
    uniform vec4 ball_fs_params[1];
    uniform sampler2D ball_normal_map;
    
    in vec2 frag_texture_coord;
    in vec3 frag_normal;
    layout(location = 0) out vec4 g_frag_color;
    
    void main()
    {
        float _48 = abs(dot(normalize((texture(ball_normal_map, vec2(frag_texture_coord.x, 1.0 - frag_texture_coord.y)).xyz * 2.0) - vec3(1.0)), vec3(-0.1881441771984100341796875, -0.282216250896453857421875, -0.940720856189727783203125)));
        float kd0 = _48;
        if (_48 < 0.0)
        {
            kd0 = 0.0;
        }
        float _64 = (normalize(frag_normal).y + 1.0) * 0.5;
        float kd1 = _64;
        if (_64 < 0.300000011920928955078125)
        {
            kd1 = 0.300000011920928955078125;
        }
        g_frag_color = vec4(ball_fs_params[0].xyz * (kd0 * kd1), 1.0);
    }
    
*/
static const char ball_fs_source_glsl330[742] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x62,0x61,0x6c,0x6c,0x5f,
    0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x32,0x44,0x20,
    0x62,0x61,0x6c,0x6c,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x5f,0x6d,0x61,0x70,0x3b,
    0x0a,0x0a,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x74,
    0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x33,0x20,0x66,0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,
    0x6c,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,
    0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,
    0x20,0x67,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,
    0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,
    0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x34,0x38,0x20,0x3d,0x20,0x61,0x62,
    0x73,0x28,0x64,0x6f,0x74,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,
    0x28,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x62,0x61,0x6c,0x6c,0x5f,0x6e,0x6f,
    0x72,0x6d,0x61,0x6c,0x5f,0x6d,0x61,0x70,0x2c,0x20,0x76,0x65,0x63,0x32,0x28,0x66,
    0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,
    0x64,0x2e,0x78,0x2c,0x20,0x31,0x2e,0x30,0x20,0x2d,0x20,0x66,0x72,0x61,0x67,0x5f,
    0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x2e,0x79,0x29,
    0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x32,0x2e,0x30,0x29,0x20,0x2d,0x20,0x76,
    0x65,0x63,0x33,0x28,0x31,0x2e,0x30,0x29,0x29,0x2c,0x20,0x76,0x65,0x63,0x33,0x28,
    0x2d,0x30,0x2e,0x31,0x38,0x38,0x31,0x34,0x34,0x31,0x37,0x37,0x31,0x39,0x38,0x34,
    0x31,0x30,0x30,0x33,0x34,0x31,0x37,0x39,0x36,0x38,0x37,0x35,0x2c,0x20,0x2d,0x30,
    0x2e,0x32,0x38,0x32,0x32,0x31,0x36,0x32,0x35,0x30,0x38,0x39,0x36,0x34,0x35,0x33,
    0x38,0x35,0x37,0x34,0x32,0x31,0x38,0x37,0x35,0x2c,0x20,0x2d,0x30,0x2e,0x39,0x34,
    0x30,0x37,0x32,0x30,0x38,0x35,0x36,0x31,0x38,0x39,0x37,0x32,0x37,0x37,0x38,0x33,
    0x32,0x30,0x33,0x31,0x32,0x35,0x29,0x29,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x20,0x6b,0x64,0x30,0x20,0x3d,0x20,0x5f,0x34,0x38,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x34,0x38,0x20,0x3c,0x20,0x30,0x2e,
    0x30,0x29,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
    0x20,0x6b,0x64,0x30,0x20,0x3d,0x20,0x30,0x2e,0x30,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x7d,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x36,0x34,0x20,
    0x3d,0x20,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x66,0x72,0x61,
    0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x29,0x2e,0x79,0x20,0x2b,0x20,0x31,0x2e,
    0x30,0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,
    0x6f,0x61,0x74,0x20,0x6b,0x64,0x31,0x20,0x3d,0x20,0x5f,0x36,0x34,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x36,0x34,0x20,0x3c,0x20,0x30,0x2e,0x33,
    0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x39,0x32,0x30,0x39,0x32,0x38,0x39,0x35,
    0x35,0x30,0x37,0x38,0x31,0x32,0x35,0x29,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x6b,0x64,0x31,0x20,0x3d,0x20,0x30,0x2e,0x33,
    0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x39,0x32,0x30,0x39,0x32,0x38,0x39,0x35,
    0x35,0x30,0x37,0x38,0x31,0x32,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,
    0x20,0x20,0x20,0x67,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,
    0x3d,0x20,0x76,0x65,0x63,0x34,0x28,0x62,0x61,0x6c,0x6c,0x5f,0x66,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x28,
    0x6b,0x64,0x30,0x20,0x2a,0x20,0x6b,0x64,0x31,0x29,0x2c,0x20,0x31,0x2e,0x30,0x29,
    0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 300 es
    
    uniform vec4 ball_vs_params[8];
    layout(location = 0) in vec3 position;
    out vec3 frag_normal;
    layout(location = 1) in vec3 normal;
    out vec2 frag_texture_coord;
    layout(location = 2) in vec2 texture_coord;
    
    void main()
    {
        mat4 _27 = mat4(ball_vs_params[4], ball_vs_params[5], ball_vs_params[6], ball_vs_params[7]);
        gl_Position = (mat4(ball_vs_params[0], ball_vs_params[1], ball_vs_params[2], ball_vs_params[3]) * _27) * vec4(position, 1.0);
        frag_normal = normalize((transpose(inverse(_27)) * vec4(normal, 0.0)).xyz);
        frag_texture_coord = texture_coord;
    }
    
*/
static const char ball_vs_source_glsl300es[586] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x62,0x61,
    0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x38,0x5d,0x3b,
    0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,
    0x20,0x3d,0x20,0x30,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x70,0x6f,
    0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6c,0x61,
    0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,
    0x31,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x6e,0x6f,0x72,0x6d,0x61,
    0x6c,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,
    0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,
    0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
    0x3d,0x20,0x32,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x74,0x65,0x78,
    0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x0a,0x76,0x6f,0x69,
    0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,
    0x61,0x74,0x34,0x20,0x5f,0x32,0x37,0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x62,
    0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,
    0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x35,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x36,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,
    0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x37,0x5d,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x28,0x6d,
    0x61,0x74,0x34,0x28,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,0x5d,0x2c,0x20,0x62,0x61,0x6c,
    0x6c,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x20,
    0x2a,0x20,0x5f,0x32,0x37,0x29,0x20,0x2a,0x20,0x76,0x65,0x63,0x34,0x28,0x70,0x6f,
    0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x20,0x3d,0x20,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x28,0x74,0x72,0x61,0x6e,0x73,
    0x70,0x6f,0x73,0x65,0x28,0x69,0x6e,0x76,0x65,0x72,0x73,0x65,0x28,0x5f,0x32,0x37,
    0x29,0x29,0x20,0x2a,0x20,0x76,0x65,0x63,0x34,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,
    0x2c,0x20,0x30,0x2e,0x30,0x29,0x29,0x2e,0x78,0x79,0x7a,0x29,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,
    0x6f,0x6f,0x72,0x64,0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,
    0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 300 es
    precision mediump float;
    precision highp int;
    
    uniform highp vec4 ball_fs_params[1];
    uniform highp sampler2D ball_normal_map;
    
    in highp vec2 frag_texture_coord;
    in highp vec3 frag_normal;
    layout(location = 0) out highp vec4 g_frag_color;
    
    void main()
    {
        highp float _48 = abs(dot(normalize((texture(ball_normal_map, vec2(frag_texture_coord.x, 1.0 - frag_texture_coord.y)).xyz * 2.0) - vec3(1.0)), vec3(-0.1881441771984100341796875, -0.282216250896453857421875, -0.940720856189727783203125)));
        highp float kd0 = _48;
        if (_48 < 0.0)
        {
            kd0 = 0.0;
        }
        highp float _64 = (normalize(frag_normal).y + 1.0) * 0.5;
        highp float kd1 = _64;
        if (_64 < 0.300000011920928955078125)
        {
            kd1 = 0.300000011920928955078125;
        }
        g_frag_color = vec4(ball_fs_params[0].xyz * (kd0 * kd1), 1.0);
    }
    
*/
static const char ball_fs_source_glsl300es[845] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x70,0x72,0x65,0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,0x6d,0x65,0x64,0x69,0x75,0x6d,
    0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x3b,0x0a,0x70,0x72,0x65,0x63,0x69,0x73,0x69,
    0x6f,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x69,0x6e,0x74,0x3b,0x0a,0x0a,0x75,
    0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,
    0x34,0x20,0x62,0x61,0x6c,0x6c,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,
    0x68,0x70,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x32,0x44,0x20,0x62,0x61,0x6c,
    0x6c,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x5f,0x6d,0x61,0x70,0x3b,0x0a,0x0a,0x69,
    0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,
    0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,
    0x0a,0x69,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x33,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6c,0x61,0x79,0x6f,
    0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,
    0x20,0x6f,0x75,0x74,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x34,0x20,
    0x67,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,
    0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,
    0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x34,0x38,
    0x20,0x3d,0x20,0x61,0x62,0x73,0x28,0x64,0x6f,0x74,0x28,0x6e,0x6f,0x72,0x6d,0x61,
    0x6c,0x69,0x7a,0x65,0x28,0x28,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x62,0x61,
    0x6c,0x6c,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x5f,0x6d,0x61,0x70,0x2c,0x20,0x76,
    0x65,0x63,0x32,0x28,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,
    0x5f,0x63,0x6f,0x6f,0x72,0x64,0x2e,0x78,0x2c,0x20,0x31,0x2e,0x30,0x20,0x2d,0x20,
    0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,
    0x72,0x64,0x2e,0x79,0x29,0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x32,0x2e,0x30,
    0x29,0x20,0x2d,0x20,0x76,0x65,0x63,0x33,0x28,0x31,0x2e,0x30,0x29,0x29,0x2c,0x20,
    0x76,0x65,0x63,0x33,0x28,0x2d,0x30,0x2e,0x31,0x38,0x38,0x31,0x34,0x34,0x31,0x37,
    0x37,0x31,0x39,0x38,0x34,0x31,0x30,0x30,0x33,0x34,0x31,0x37,0x39,0x36,0x38,0x37,
    0x35,0x2c,0x20,0x2d,0x30,0x2e,0x32,0x38,0x32,0x32,0x31,0x36,0x32,0x35,0x30,0x38,
    0x39,0x36,0x34,0x35,0x33,0x38,0x35,0x37,0x34,0x32,0x31,0x38,0x37,0x35,0x2c,0x20,
    0x2d,0x30,0x2e,0x39,0x34,0x30,0x37,0x32,0x30,0x38,0x35,0x36,0x31,0x38,0x39,0x37,
    0x32,0x37,0x37,0x38,0x33,0x32,0x30,0x33,0x31,0x32,0x35,0x29,0x29,0x29,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,
    0x6b,0x64,0x30,0x20,0x3d,0x20,0x5f,0x34,0x38,0x3b,0x0a,0x20,0x20,0x20,0x20,0x69,
    0x66,0x20,0x28,0x5f,0x34,0x38,0x20,0x3c,0x20,0x30,0x2e,0x30,0x29,0x0a,0x20,0x20,
    0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x6b,0x64,0x30,0x20,
    0x3d,0x20,0x30,0x2e,0x30,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,
    0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x36,0x34,
    0x20,0x3d,0x20,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x66,0x72,
    0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x29,0x2e,0x79,0x20,0x2b,0x20,0x31,
    0x2e,0x30,0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x68,
    0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x6b,0x64,0x31,0x20,0x3d,
    0x20,0x5f,0x36,0x34,0x3b,0x0a,0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x36,
    0x34,0x20,0x3c,0x20,0x30,0x2e,0x33,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x39,
    0x32,0x30,0x39,0x32,0x38,0x39,0x35,0x35,0x30,0x37,0x38,0x31,0x32,0x35,0x29,0x0a,
    0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x6b,0x64,
    0x31,0x20,0x3d,0x20,0x30,0x2e,0x33,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x39,
    0x32,0x30,0x39,0x32,0x38,0x39,0x35,0x35,0x30,0x37,0x38,0x31,0x32,0x35,0x3b,0x0a,
    0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x67,0x5f,0x66,0x72,0x61,0x67,
    0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x76,0x65,0x63,0x34,0x28,0x62,0x61,
    0x6c,0x6c,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2e,
    0x78,0x79,0x7a,0x20,0x2a,0x20,0x28,0x6b,0x64,0x30,0x20,0x2a,0x20,0x6b,0x64,0x31,
    0x29,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before ball.glsl.h"
#endif
static inline const sg_shader_desc* ball_shader_desc(sg_backend backend) {
  if (backend == SG_BACKEND_GLCORE33) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "position";
      desc.attrs[1].name = "normal";
      desc.attrs[2].name = "texture_coord";
      desc.vs.source = ball_vs_source_glsl330;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 128;
      desc.vs.uniform_blocks[0].uniforms[0].name = "ball_vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 8;
      desc.fs.source = ball_fs_source_glsl330;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "ball_fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.fs.images[0].name = "ball_normal_map";
      desc.fs.images[0].image_type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "ball_shader";
    }
    return &desc;
  }
  if (backend == SG_BACKEND_GLES3) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "position";
      desc.attrs[1].name = "normal";
      desc.attrs[2].name = "texture_coord";
      desc.vs.source = ball_vs_source_glsl300es;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 128;
      desc.vs.uniform_blocks[0].uniforms[0].name = "ball_vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 8;
      desc.fs.source = ball_fs_source_glsl300es;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "ball_fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.fs.images[0].name = "ball_normal_map";
      desc.fs.images[0].image_type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "ball_shader";
    }
    return &desc;
  }
  return 0;
}