// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Nirtcpp.h

#ifndef NIRT_C_OPEN_GL_FEATURE_MAP_H_INCLUDED
#define NIRT_C_OPEN_GL_FEATURE_MAP_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef _NIRT_COMPILE_WITH_OPENGL_

#include <nirtcpp/EDriverFeatures.hpp>
#include <nirtcpp/irrTypes.hpp>
#include "os.hpp"

#include "COpenGLCommon.hpp"

#include "COpenGLCoreFeature.hpp"

namespace nirt
{
namespace video
{

static const char* const OpenGLFeatureStrings[] = {
	"GL_3DFX_multisample",
	"GL_3DFX_tbuffer",
	"GL_3DFX_texture_compression_FXT1",
	"GL_AMD_blend_minmax_factor",
	"GL_AMD_conservative_depth",
	"GL_AMD_debug_output",
	"GL_AMD_depth_clamp_separate",
	"GL_AMD_draw_buffers_blend",
	"GL_AMD_interleaved_elements",
	"GL_AMD_multi_draw_indirect",
	"GL_AMD_name_gen_delete",
	"GL_AMD_performance_monitor",
	"GL_AMD_pinned_memory",
	"GL_AMD_query_buffer_object",
	"GL_AMD_sample_positions",
	"GL_AMD_seamless_cubemap_per_texture",
	"GL_AMD_shader_atomic_counter_ops",
	"GL_AMD_shader_stencil_export",
	"GL_AMD_shader_trinary_minmax",
	"GL_AMD_sparse_texture",
	"GL_AMD_stencil_operation_extended",
	"GL_AMD_texture_texture4",
	"GL_AMD_transform_feedback3_lines_triangles",
	"GL_AMD_vertex_shader_layer",
	"GL_AMD_vertex_shader_tessellator",
	"GL_AMD_vertex_shader_viewport_index",
	"GL_APPLE_aux_depth_stencil",
	"GL_APPLE_client_storage",
	"GL_APPLE_element_array",
	"GL_APPLE_fence",
	"GL_APPLE_float_pixels",
	"GL_APPLE_flush_buffer_range",
	"GL_APPLE_object_purgeable",
	"GL_APPLE_rgb_422",
	"GL_APPLE_row_bytes",
	"GL_APPLE_specular_vector",
	"GL_APPLE_texture_range",
	"GL_APPLE_transform_hint",
	"GL_APPLE_vertex_array_object",
	"GL_APPLE_vertex_array_range",
	"GL_APPLE_vertex_program_evaluators",
	"GL_APPLE_ycbcr_422",
	"GL_ARB_ES3_compatibility",
	"GL_ARB_arrays_of_arrays",
	"GL_ARB_base_instance",
	"GL_ARB_bindless_texture",
	"GL_ARB_blend_func_extended",
	"GL_ARB_buffer_storage",
	"GL_ARB_cl_event",
	"GL_ARB_clear_buffer_object",
	"GL_ARB_clear_texture",
	"GL_ARB_color_buffer_float",
	"GL_ARB_compatibility",
	"GL_ARB_compressed_texture_pixel_storage",
	"GL_ARB_compute_shader",
	"GL_ARB_compute_variable_group_size",
	"GL_ARB_conservative_depth",
	"GL_ARB_copy_buffer",
	"GL_ARB_copy_image",
	"GL_ARB_debug_output",
	"GL_ARB_depth_buffer_float",
	"GL_ARB_depth_clamp",
	"GL_ARB_depth_texture",
	"GL_ARB_direct_state_access",
	"GL_ARB_draw_buffers",
	"GL_ARB_draw_buffers_blend",
	"GL_ARB_draw_elements_base_vertex",
	"GL_ARB_draw_indirect",
	"GL_ARB_draw_instanced",
	"GL_ARB_ES2_compatibility",
	"GL_ARB_enhanced_layouts",
	"GL_ARB_explicit_attrib_location",
	"GL_ARB_explicit_uniform_location",
	"GL_ARB_fragment_coord_conventions",
	"GL_ARB_fragment_layer_viewport",
	"GL_ARB_fragment_program",
	"GL_ARB_fragment_program_shadow",
	"GL_ARB_fragment_shader",
	"GL_ARB_framebuffer_no_attachments",
	"GL_ARB_framebuffer_object",
	"GL_ARB_framebuffer_sRGB",
	"GL_ARB_geometry_shader4",
	"GL_ARB_get_program_binary",
	"GL_ARB_gpu_shader5",
	"GL_ARB_gpu_shader_fp64",
	"GL_ARB_half_float_pixel",
	"GL_ARB_half_float_vertex",
	"GL_ARB_imaging",
	"GL_ARB_indirect_parameters",
	"GL_ARB_instanced_arrays",
	"GL_ARB_internalformat_query",
	"GL_ARB_internalformat_query2",
	"GL_ARB_invalidate_subdata",
	"GL_ARB_map_buffer_alignment",
	"GL_ARB_map_buffer_range",
	"GL_ARB_matrix_palette",
	"GL_ARB_multi_bind",
	"GL_ARB_multi_draw_indirect",
	"GL_ARB_multisample",
	"GL_ARB_multitexture",
	"GL_ARB_occlusion_query",
	"GL_ARB_occlusion_query2",
	"GL_ARB_pixel_buffer_object",
	"GL_ARB_point_parameters",
	"GL_ARB_point_sprite",
	"GL_ARB_program_interface_query",
	"GL_ARB_provoking_vertex",
	"GL_ARB_query_buffer_object",
	"GL_ARB_robust_buffer_access_behavior",
	"GL_ARB_robustness",
	"GL_ARB_robustness_isolation",
	"GL_ARB_sample_shading",
	"GL_ARB_sampler_objects",
	"GL_ARB_seamless_cube_map",
	"GL_ARB_seamless_cubemap_per_texture",
	"GL_ARB_separate_shader_objects",
	"GL_ARB_shader_atomic_counters",
	"GL_ARB_shader_bit_encoding",
	"GL_ARB_shader_draw_parameters",
	"GL_ARB_shader_group_vote",
	"GL_ARB_shader_image_load_store",
	"GL_ARB_shader_image_size",
	"GL_ARB_shader_objects",
	"GL_ARB_shader_precision",
	"GL_ARB_shader_stencil_export",
	"GL_ARB_shader_storage_buffer_object",
	"GL_ARB_shader_subroutine",
	"GL_ARB_shader_texture_lod",
	"GL_ARB_shading_language_100",
	"GL_ARB_shading_language_420pack",
	"GL_ARB_shading_language_include",
	"GL_ARB_shading_language_packing",
	"GL_ARB_shadow",
	"GL_ARB_shadow_ambient",
	"GL_ARB_sparse_texture",
	"GL_ARB_stencil_texturing",
	"GL_ARB_sync",
	"GL_ARB_tessellation_shader",
	"GL_ARB_texture_border_clamp",
	"GL_ARB_texture_buffer_object",
	"GL_ARB_texture_buffer_object_rgb32",
	"GL_ARB_texture_buffer_range",
	"GL_ARB_texture_compression",
	"GL_ARB_texture_compression_bptc",
	"GL_ARB_texture_compression_rgtc",
	"GL_ARB_texture_cube_map",
	"GL_ARB_texture_cube_map_array",
	"GL_ARB_texture_env_add",
	"GL_ARB_texture_env_combine",
	"GL_ARB_texture_env_crossbar",
	"GL_ARB_texture_env_dot3",
	"GL_ARB_texture_float",
	"GL_ARB_texture_gather",
	"GL_ARB_texture_mirror_clamp_to_edge",
	"GL_ARB_texture_mirrored_repeat",
	"GL_ARB_texture_multisample",
	"GL_ARB_texture_non_power_of_two",
	"GL_ARB_texture_query_levels",
	"GL_ARB_texture_query_lod",
	"GL_ARB_texture_rectangle",
	"GL_ARB_texture_rg",
	"GL_ARB_texture_rgb10_a2ui",
	"GL_ARB_texture_stencil8",
	"GL_ARB_texture_storage",
	"GL_ARB_texture_storage_multisample",
	"GL_ARB_texture_swizzle",
	"GL_ARB_texture_view",
	"GL_ARB_timer_query",
	"GL_ARB_transform_feedback2",
	"GL_ARB_transform_feedback3",
	"GL_ARB_transform_feedback_instanced",
	"GL_ARB_transpose_matrix",
	"GL_ARB_uniform_buffer_object",
	"GL_ARB_vertex_array_bgra",
	"GL_ARB_vertex_array_object",
	"GL_ARB_vertex_attrib_64bit",
	"GL_ARB_vertex_attrib_binding",
	"GL_ARB_vertex_blend",
	"GL_ARB_vertex_buffer_object",
	"GL_ARB_vertex_program",
	"GL_ARB_vertex_shader",
	"GL_ARB_vertex_type_10f_11f_11f_rev",
	"GL_ARB_vertex_type_2_10_10_10_rev",
	"GL_ARB_viewport_array",
	"GL_ARB_window_pos",
	"GL_ATI_draw_buffers",
	"GL_ATI_element_array",
	"GL_ATI_envmap_bumpmap",
	"GL_ATI_fragment_shader",
	"GL_ATI_map_object_buffer",
	"GL_ATI_meminfo",
	"GL_ATI_pixel_format_float",
	"GL_ATI_pn_triangles",
	"GL_ATI_separate_stencil",
	"GL_ATI_text_fragment_shader",
	"GL_ATI_texture_env_combine3",
	"GL_ATI_texture_float",
	"GL_ATI_texture_mirror_once",
	"GL_ATI_vertex_array_object",
	"GL_ATI_vertex_attrib_array_object",
	"GL_ATI_vertex_streams",
	"GL_EXT_422_pixels",
	"GL_EXT_abgr",
	"GL_EXT_bgra",
	"GL_EXT_bindable_uniform",
	"GL_EXT_blend_color",
	"GL_EXT_blend_equation_separate",
	"GL_EXT_blend_func_separate",
	"GL_EXT_blend_logic_op",
	"GL_EXT_blend_minmax",
	"GL_EXT_blend_subtract",
	"GL_EXT_clip_volume_hint",
	"GL_EXT_cmyka",
	"GL_EXT_color_subtable",
	"GL_EXT_compiled_vertex_array",
	"GL_EXT_convolution",
	"GL_EXT_coordinate_frame",
	"GL_EXT_copy_texture",
	"GL_EXT_cull_vertex",
	"GL_EXT_debug_label",
	"GL_EXT_debug_marker",
	"GL_EXT_depth_bounds_test",
	"GL_EXT_direct_state_access",
	"GL_EXT_draw_buffers2",
	"GL_EXT_draw_instanced",
	"GL_EXT_draw_range_elements",
	"GL_EXT_fog_coord",
	"GL_EXT_framebuffer_blit",
	"GL_EXT_framebuffer_multisample",
	"GL_EXT_framebuffer_multisample_blit_scaled",
	"GL_EXT_framebuffer_object",
	"GL_EXT_framebuffer_sRGB",
	"GL_EXT_geometry_shader4",
	"GL_EXT_gpu_program_parameters",
	"GL_EXT_gpu_shader4",
	"GL_EXT_histogram",
	"GL_EXT_index_array_formats",
	"GL_EXT_index_func",
	"GL_EXT_index_material",
	"GL_EXT_index_texture",
	"GL_EXT_light_texture",
	"GL_EXT_misc_attribute",
	"GL_EXT_multi_draw_arrays",
	"GL_EXT_multisample",
	"GL_EXT_packed_depth_stencil",
	"GL_EXT_packed_float",
	"GL_EXT_packed_pixels",
	"GL_EXT_paletted_texture",
	"GL_EXT_pixel_buffer_object",
	"GL_EXT_pixel_transform",
	"GL_EXT_pixel_transform_color_table",
	"GL_EXT_point_parameters",
	"GL_EXT_polygon_offset",
	"GL_EXT_provoking_vertex",
	"GL_EXT_rescale_normal",
	"GL_EXT_secondary_color",
	"GL_EXT_separate_shader_objects",
	"GL_EXT_separate_specular_color",
	"GL_EXT_shader_image_load_store",
	"GL_EXT_shader_integer_mix",
	"GL_EXT_shadow_funcs",
	"GL_EXT_shared_texture_palette",
	"GL_EXT_stencil_clear_tag",
	"GL_EXT_stencil_two_side",
	"GL_EXT_stencil_wrap",
	"GL_EXT_subtexture",
	"GL_EXT_texture",
	"GL_EXT_texture3D",
	"GL_EXT_texture_array",
	"GL_EXT_texture_buffer_object",
	"GL_EXT_texture_compression_latc",
	"GL_EXT_texture_compression_rgtc",
	"GL_EXT_texture_compression_s3tc",
	"GL_EXT_texture_cube_map",
	"GL_EXT_texture_env_add",
	"GL_EXT_texture_env_combine",
	"GL_EXT_texture_env_dot3",
	"GL_EXT_texture_filter_anisotropic",
	"GL_EXT_texture_integer",
	"GL_EXT_texture_lod_bias",
	"GL_EXT_texture_mirror_clamp",
	"GL_EXT_texture_object",
	"GL_EXT_texture_perturb_normal",
	"GL_EXT_texture_shared_exponent",
	"GL_EXT_texture_snorm",
	"GL_EXT_texture_sRGB",
	"GL_EXT_texture_sRGB_decode",
	"GL_EXT_texture_swizzle",
	"GL_EXT_timer_query",
	"GL_EXT_transform_feedback",
	"GL_EXT_vertex_array",
	"GL_EXT_vertex_array_bgra",
	"GL_EXT_vertex_attrib_64bit",
	"GL_EXT_vertex_shader",
	"GL_EXT_vertex_weighting",
	"GL_EXT_x11_sync_object",
	"GL_GREMEDY_frame_terminator",
	"GL_GREMEDY_string_marker",
	"GL_HP_convolution_border_modes",
	"GL_HP_image_transform",
	"GL_HP_occlusion_test",
	"GL_HP_texture_lighting",
	"GL_IBM_cull_vertex",
	"GL_IBM_multimode_draw_arrays",
	"GL_IBM_rasterpos_clip",
	"GL_IBM_static_data",
	"GL_IBM_texture_mirrored_repeat",
	"GL_IBM_vertex_array_lists",
	"GL_INGR_blend_func_separate",
	"GL_INGR_color_clamp",
	"GL_INGR_interlace_read",
	"GL_INGR_palette_buffer",
	"GL_INTEL_map_texture",
	"GL_INTEL_parallel_arrays",
	"GL_INTEL_texture_scissor",
	"GL_KHR_debug",
	"GL_KHR_texture_compression_astc_hdr",
	"GL_KHR_texture_compression_astc_ldr",
	"GL_MESA_pack_invert",
	"GL_MESA_resize_buffers",
	"GL_MESA_window_pos",
	"GL_MESAX_texture_stack",
	"GL_MESA_ycbcr_texture",
	"GL_NVX_conditional_render",
	"GL_NV_bindless_multi_draw_indirect",
	"GL_NV_bindless_texture",
	"GL_NV_blend_equation_advanced",
	"GL_NV_blend_equation_advanced_coherent",
	"GL_NV_blend_square",
	"GL_NV_compute_program5",
	"GL_NV_conditional_render",
	"GL_NV_copy_depth_to_color",
	"GL_NV_copy_image",
	"GL_NV_deep_texture3D",
	"GL_NV_depth_buffer_float",
	"GL_NV_depth_clamp",
	"GL_NV_draw_texture",
	"GL_NV_evaluators",
	"GL_NV_explicit_multisample",
	"GL_NV_fence",
	"GL_NV_float_buffer",
	"GL_NV_fog_distance",
	"GL_NV_fragment_program",
	"GL_NV_fragment_program2",
	"GL_NV_fragment_program4",
	"GL_NV_fragment_program_option",
	"GL_NV_framebuffer_multisample_coverage",
	"GL_NV_geometry_program4",
	"GL_NV_geometry_shader4",
	"GL_NV_gpu_program4",
	"GL_NV_gpu_program5",
	"GL_NV_gpu_program5_mem_extended",
	"GL_NV_gpu_shader5",
	"GL_NV_half_float",
	"GL_NV_light_max_exponent",
	"GL_NV_multisample_coverage",
	"GL_NV_multisample_filter_hint",
	"GL_NV_occlusion_query",
	"GL_NV_packed_depth_stencil",
	"GL_NV_parameter_buffer_object",
	"GL_NV_parameter_buffer_object2",
	"GL_NV_path_rendering",
	"GL_NV_pixel_data_range",
	"GL_NV_point_sprite",
	"GL_NV_present_video",
	"GL_NV_primitive_restart",
	"GL_NV_register_combiners",
	"GL_NV_register_combiners2",
	"GL_NV_shader_atomic_counters",
	"GL_NV_shader_atomic_float",
	"GL_NV_shader_buffer_load",
	"GL_NV_shader_buffer_store",
	"GL_NV_shader_storage_buffer_object",
	"GL_NV_tessellation_program5",
	"GL_NV_texgen_emboss",
	"GL_NV_texgen_reflection",
	"GL_NV_texture_barrier",
	"GL_NV_texture_compression_vtc",
	"GL_NV_texture_env_combine4",
	"GL_NV_texture_expand_normal",
	"GL_NV_texture_multisample",
	"GL_NV_texture_rectangle",
	"GL_NV_texture_shader",
	"GL_NV_texture_shader2",
	"GL_NV_texture_shader3",
	"GL_NV_transform_feedback",
	"GL_NV_transform_feedback2",
	"GL_NV_vdpau_interop",
	"GL_NV_vertex_array_range",
	"GL_NV_vertex_array_range2",
	"GL_NV_vertex_attrib_integer_64bit",
	"GL_NV_vertex_buffer_unified_memory",
	"GL_NV_vertex_program",
	"GL_NV_vertex_program1_1",
	"GL_NV_vertex_program2",
	"GL_NV_vertex_program2_option",
	"GL_NV_vertex_program3",
	"GL_NV_vertex_program4",
	"GL_NV_video_capture",
	"GL_OES_byte_coordinates",
	"GL_OES_compressed_paletted_texture",
	"GL_OES_fixed_point",
	"GL_OES_query_matrix",
	"GL_OES_read_format",
	"GL_OES_single_precision",
	"GL_OML_interlace",
	"GL_OML_resample",
	"GL_OML_subsample",
	"GL_PGI_misc_hints",
	"GL_PGI_vertex_hints",
	"GL_REND_screen_coordinates",
	"GL_S3_s3tc",
	"GL_SGI_color_matrix",
	"GL_SGI_color_table",
	"GL_SGI_texture_color_table",
	"GL_SGIS_detail_texture",
	"GL_SGIS_fog_function",
	"GL_SGIS_generate_mipmap",
	"GL_SGIS_multisample",
	"GL_SGIS_pixel_texture",
	"GL_SGIS_point_line_texgen",
	"GL_SGIS_point_parameters",
	"GL_SGIS_sharpen_texture",
	"GL_SGIS_texture4D",
	"GL_SGIS_texture_border_clamp",
	"GL_SGIS_texture_color_mask",
	"GL_SGIS_texture_edge_clamp",
	"GL_SGIS_texture_filter4",
	"GL_SGIS_texture_lod",
	"GL_SGIS_texture_select",
	"GL_SGIX_async",
	"GL_SGIX_async_histogram",
	"GL_SGIX_async_pixel",
	"GL_SGIX_blend_alpha_minmax",
	"GL_SGIX_calligraphic_fragment",
	"GL_SGIX_clipmap",
	"GL_SGIX_convolution_accuracy",
	"GL_SGIX_depth_pass_instrument",
	"GL_SGIX_depth_texture",
	"GL_SGIX_flush_raster",
	"GL_SGIX_fog_offset",
	"GL_SGIX_fog_scale",
	"GL_SGIX_fragment_lighting",
	"GL_SGIX_framezoom",
	"GL_SGIX_igloo_interface",
	"GL_SGIX_instruments",
	"GL_SGIX_interlace",
	"GL_SGIX_ir_instrument1",
	"GL_SGIX_list_priority",
	"GL_SGIX_pixel_texture",
	"GL_SGIX_pixel_tiles",
	"GL_SGIX_polynomial_ffd",
	"GL_SGIX_reference_plane",
	"GL_SGIX_resample",
	"GL_SGIX_scalebias_hint",
	"GL_SGIX_shadow",
	"GL_SGIX_shadow_ambient",
	"GL_SGIX_sprite",
	"GL_SGIX_subsample",
	"GL_SGIX_tag_sample_buffer",
	"GL_SGIX_texture_add_env",
	"GL_SGIX_texture_coordinate_clamp",
	"GL_SGIX_texture_lod_bias",
	"GL_SGIX_texture_multi_buffer",
	"GL_SGIX_texture_scale_bias",
	"GL_SGIX_vertex_preclip",
	"GL_SGIX_ycrcb",
	"GL_SGIX_ycrcba",
	"GL_SGIX_ycrcb_subsample",
	"GL_SUN_convolution_border_modes",
	"GL_SUN_global_alpha",
	"GL_SUN_mesh_array",
	"GL_SUN_slice_accum",
	"GL_SUN_triangle_list",
	"GL_SUN_vertex",
	"GL_SUNX_constant_data",
	"GL_WIN_phong_shading",
	"GL_WIN_specular_fog",
	// unofficial stuff
	"GL_NVX_gpu_memory_info"
};


class COpenGLExtensionHandler
{
	public:
	enum EOpenGLFeatures {
		NIRT_3DFX_multisample = 0,
		NIRT_3DFX_tbuffer,
		NIRT_3DFX_texture_compression_FXT1,
		NIRT_AMD_blend_minmax_factor,
		NIRT_AMD_conservative_depth,
		NIRT_AMD_debug_output,
		NIRT_AMD_depth_clamp_separate,
		NIRT_AMD_draw_buffers_blend,
		NIRT_AMD_interleaved_elements,
		NIRT_AMD_multi_draw_indirect,
		NIRT_AMD_name_gen_delete,
		NIRT_AMD_performance_monitor,
		NIRT_AMD_pinned_memory,
		NIRT_AMD_query_buffer_object,
		NIRT_AMD_sample_positions,
		NIRT_AMD_seamless_cubemap_per_texture,
		NIRT_AMD_shader_atomic_counter_ops,
		NIRT_AMD_shader_stencil_export,
		NIRT_AMD_shader_trinary_minmax,
		NIRT_AMD_sparse_texture,
		NIRT_AMD_stencil_operation_extended,
		NIRT_AMD_texture_texture4,
		NIRT_AMD_transform_feedback3_lines_triangles,
		NIRT_AMD_vertex_shader_layer,
		NIRT_AMD_vertex_shader_tessellator,
		NIRT_AMD_vertex_shader_viewport_index,
		NIRT_APPLE_aux_depth_stencil,
		NIRT_APPLE_client_storage,
		NIRT_APPLE_element_array,
		NIRT_APPLE_fence,
		NIRT_APPLE_float_pixels,
		NIRT_APPLE_flush_buffer_range,
		NIRT_APPLE_object_purgeable,
		NIRT_APPLE_rgb_422,
		NIRT_APPLE_row_bytes,
		NIRT_APPLE_specular_vector,
		NIRT_APPLE_texture_range,
		NIRT_APPLE_transform_hint,
		NIRT_APPLE_vertex_array_object,
		NIRT_APPLE_vertex_array_range,
		NIRT_APPLE_vertex_program_evaluators,
		NIRT_APPLE_ycbcr_422,
		NIRT_ARB_ES3_compatibility,
		NIRT_ARB_arrays_of_arrays,
		NIRT_ARB_base_instance,
		NIRT_ARB_bindless_texture,
		NIRT_ARB_blend_func_extended,
		NIRT_ARB_buffer_storage,
		NIRT_ARB_cl_event,
		NIRT_ARB_clear_buffer_object,
		NIRT_ARB_clear_texture,
		NIRT_ARB_color_buffer_float,
		NIRT_ARB_compatibility,
		NIRT_ARB_compressed_texture_pixel_storage,
		NIRT_ARB_compute_shader,
		NIRT_ARB_compute_variable_group_size,
		NIRT_ARB_conservative_depth,
		NIRT_ARB_copy_buffer,
		NIRT_ARB_copy_image,
		NIRT_ARB_debug_output,
		NIRT_ARB_depth_buffer_float,
		NIRT_ARB_depth_clamp,
		NIRT_ARB_depth_texture,
		NIRT_ARB_direct_state_access,
		NIRT_ARB_draw_buffers,
		NIRT_ARB_draw_buffers_blend,
		NIRT_ARB_draw_elements_base_vertex,
		NIRT_ARB_draw_indirect,
		NIRT_ARB_draw_instanced,
		NIRT_ARB_ES2_compatibility,
		NIRT_ARB_enhanced_layouts,
		NIRT_ARB_explicit_attrib_location,
		NIRT_ARB_explicit_uniform_location,
		NIRT_ARB_fragment_coord_conventions,
		NIRT_ARB_fragment_layer_viewport,
		NIRT_ARB_fragment_program,
		NIRT_ARB_fragment_program_shadow,
		NIRT_ARB_fragment_shader,
		NIRT_ARB_framebuffer_no_attachments,
		NIRT_ARB_framebuffer_object,
		NIRT_ARB_framebuffer_sRGB,
		NIRT_ARB_geometry_shader4,
		NIRT_ARB_get_program_binary,
		NIRT_ARB_gpu_shader5,
		NIRT_ARB_gpu_shader_fp64,
		NIRT_ARB_half_float_pixel,
		NIRT_ARB_half_float_vertex,
		NIRT_ARB_imaging,
		NIRT_ARB_indirect_parameters,
		NIRT_ARB_instanced_arrays,
		NIRT_ARB_internalformat_query,
		NIRT_ARB_internalformat_query2,
		NIRT_ARB_invalidate_subdata,
		NIRT_ARB_map_buffer_alignment,
		NIRT_ARB_map_buffer_range,
		NIRT_ARB_matrix_palette,
		NIRT_ARB_multi_bind,
		NIRT_ARB_multi_draw_indirect,
		NIRT_ARB_multisample,
		NIRT_ARB_multitexture,
		NIRT_ARB_occlusion_query,
		NIRT_ARB_occlusion_query2,
		NIRT_ARB_pixel_buffer_object,
		NIRT_ARB_point_parameters,
		NIRT_ARB_point_sprite,
		NIRT_ARB_program_interface_query,
		NIRT_ARB_provoking_vertex,
		NIRT_ARB_query_buffer_object,
		NIRT_ARB_robust_buffer_access_behavior,
		NIRT_ARB_robustness,
		NIRT_ARB_robustness_isolation,
		NIRT_ARB_sample_shading,
		NIRT_ARB_sampler_objects,
		NIRT_ARB_seamless_cube_map,
		NIRT_ARB_seamless_cubemap_per_texture,
		NIRT_ARB_separate_shader_objects,
		NIRT_ARB_shader_atomic_counters,
		NIRT_ARB_shader_bit_encoding,
		NIRT_ARB_shader_draw_parameters,
		NIRT_ARB_shader_group_vote,
		NIRT_ARB_shader_image_load_store,
		NIRT_ARB_shader_image_size,
		NIRT_ARB_shader_objects,
		NIRT_ARB_shader_precision,
		NIRT_ARB_shader_stencil_export,
		NIRT_ARB_shader_storage_buffer_object,
		NIRT_ARB_shader_subroutine,
		NIRT_ARB_shader_texture_lod,
		NIRT_ARB_shading_language_100,
		NIRT_ARB_shading_language_420pack,
		NIRT_ARB_shading_language_include,
		NIRT_ARB_shading_language_packing,
		NIRT_ARB_shadow,
		NIRT_ARB_shadow_ambient,
		NIRT_ARB_sparse_texture,
		NIRT_ARB_stencil_texturing,
		NIRT_ARB_sync,
		NIRT_ARB_tessellation_shader,
		NIRT_ARB_texture_border_clamp,
		NIRT_ARB_texture_buffer_object,
		NIRT_ARB_texture_buffer_object_rgb32,
		NIRT_ARB_texture_buffer_range,
		NIRT_ARB_texture_compression,
		NIRT_ARB_texture_compression_bptc,
		NIRT_ARB_texture_compression_rgtc,
		NIRT_ARB_texture_cube_map,
		NIRT_ARB_texture_cube_map_array,
		NIRT_ARB_texture_env_add,
		NIRT_ARB_texture_env_combine,
		NIRT_ARB_texture_env_crossbar,
		NIRT_ARB_texture_env_dot3,
		NIRT_ARB_texture_float,
		NIRT_ARB_texture_gather,
		NIRT_ARB_texture_mirror_clamp_to_edge,
		NIRT_ARB_texture_mirrored_repeat,
		NIRT_ARB_texture_multisample,
		NIRT_ARB_texture_non_power_of_two,
		NIRT_ARB_texture_query_levels,
		NIRT_ARB_texture_query_lod,
		NIRT_ARB_texture_rectangle,
		NIRT_ARB_texture_rg,
		NIRT_ARB_texture_rgb10_a2ui,
		NIRT_ARB_texture_stencil8,
		NIRT_ARB_texture_storage,
		NIRT_ARB_texture_storage_multisample,
		NIRT_ARB_texture_swizzle,
		NIRT_ARB_texture_view,
		NIRT_ARB_timer_query,
		NIRT_ARB_transform_feedback2,
		NIRT_ARB_transform_feedback3,
		NIRT_ARB_transform_feedback_instanced,
		NIRT_ARB_transpose_matrix,
		NIRT_ARB_uniform_buffer_object,
		NIRT_ARB_vertex_array_bgra,
		NIRT_ARB_vertex_array_object,
		NIRT_ARB_vertex_attrib_64bit,
		NIRT_ARB_vertex_attrib_binding,
		NIRT_ARB_vertex_blend,
		NIRT_ARB_vertex_buffer_object,
		NIRT_ARB_vertex_program,
		NIRT_ARB_vertex_shader,
		NIRT_ARB_vertex_type_10f_11f_11f_rev,
		NIRT_ARB_vertex_type_2_10_10_10_rev,
		NIRT_ARB_viewport_array,
		NIRT_ARB_window_pos,
		NIRT_ATI_draw_buffers,
		NIRT_ATI_element_array,
		NIRT_ATI_envmap_bumpmap,
		NIRT_ATI_fragment_shader,
		NIRT_ATI_map_object_buffer,
		NIRT_ATI_meminfo,
		NIRT_ATI_pixel_format_float,
		NIRT_ATI_pn_triangles,
		NIRT_ATI_separate_stencil,
		NIRT_ATI_text_fragment_shader,
		NIRT_ATI_texture_env_combine3,
		NIRT_ATI_texture_float,
		NIRT_ATI_texture_mirror_once,
		NIRT_ATI_vertex_array_object,
		NIRT_ATI_vertex_attrib_array_object,
		NIRT_ATI_vertex_streams,
		NIRT_EXT_422_pixels,
		NIRT_EXT_abgr,
		NIRT_EXT_bgra,
		NIRT_EXT_bindable_uniform,
		NIRT_EXT_blend_color,
		NIRT_EXT_blend_equation_separate,
		NIRT_EXT_blend_func_separate,
		NIRT_EXT_blend_logic_op,
		NIRT_EXT_blend_minmax,
		NIRT_EXT_blend_subtract,
		NIRT_EXT_clip_volume_hint,
		NIRT_EXT_cmyka,
		NIRT_EXT_color_subtable,
		NIRT_EXT_compiled_vertex_array,
		NIRT_EXT_convolution,
		NIRT_EXT_coordinate_frame,
		NIRT_EXT_copy_texture,
		NIRT_EXT_cull_vertex,
		NIRT_EXT_debug_label,
		NIRT_EXT_debug_marker,
		NIRT_EXT_depth_bounds_test,
		NIRT_EXT_direct_state_access,
		NIRT_EXT_draw_buffers2,
		NIRT_EXT_draw_instanced,
		NIRT_EXT_draw_range_elements,
		NIRT_EXT_fog_coord,
		NIRT_EXT_framebuffer_blit,
		NIRT_EXT_framebuffer_multisample,
		NIRT_EXT_framebuffer_multisample_blit_scaled,
		NIRT_EXT_framebuffer_object,
		NIRT_EXT_framebuffer_sRGB,
		NIRT_EXT_geometry_shader4,
		NIRT_EXT_gpu_program_parameters,
		NIRT_EXT_gpu_shader4,
		NIRT_EXT_histogram,
		NIRT_EXT_index_array_formats,
		NIRT_EXT_index_func,
		NIRT_EXT_index_material,
		NIRT_EXT_index_texture,
		NIRT_EXT_light_texture,
		NIRT_EXT_misc_attribute,
		NIRT_EXT_multi_draw_arrays,
		NIRT_EXT_multisample,
		NIRT_EXT_packed_depth_stencil,
		NIRT_EXT_packed_float,
		NIRT_EXT_packed_pixels,
		NIRT_EXT_paletted_texture,
		NIRT_EXT_pixel_buffer_object,
		NIRT_EXT_pixel_transform,
		NIRT_EXT_pixel_transform_color_table,
		NIRT_EXT_point_parameters,
		NIRT_EXT_polygon_offset,
		NIRT_EXT_provoking_vertex,
		NIRT_EXT_rescale_normal,
		NIRT_EXT_secondary_color,
		NIRT_EXT_separate_shader_objects,
		NIRT_EXT_separate_specular_color,
		NIRT_EXT_shader_image_load_store,
		NIRT_EXT_shader_integer_mix,
		NIRT_EXT_shadow_funcs,
		NIRT_EXT_shared_texture_palette,
		NIRT_EXT_stencil_clear_tag,
		NIRT_EXT_stencil_two_side,
		NIRT_EXT_stencil_wrap,
		NIRT_EXT_subtexture,
		NIRT_EXT_texture,
		NIRT_EXT_texture3D,
		NIRT_EXT_texture_array,
		NIRT_EXT_texture_buffer_object,
		NIRT_EXT_texture_compression_latc,
		NIRT_EXT_texture_compression_rgtc,
		NIRT_EXT_texture_compression_s3tc,
		NIRT_EXT_texture_cube_map,
		NIRT_EXT_texture_env_add,
		NIRT_EXT_texture_env_combine,
		NIRT_EXT_texture_env_dot3,
		NIRT_EXT_texture_filter_anisotropic,
		NIRT_EXT_texture_integer,
		NIRT_EXT_texture_lod_bias,
		NIRT_EXT_texture_mirror_clamp,
		NIRT_EXT_texture_object,
		NIRT_EXT_texture_perturb_normal,
		NIRT_EXT_texture_shared_exponent,
		NIRT_EXT_texture_snorm,
		NIRT_EXT_texture_sRGB,
		NIRT_EXT_texture_sRGB_decode,
		NIRT_EXT_texture_swizzle,
		NIRT_EXT_timer_query,
		NIRT_EXT_transform_feedback,
		NIRT_EXT_vertex_array,
		NIRT_EXT_vertex_array_bgra,
		NIRT_EXT_vertex_attrib_64bit,
		NIRT_EXT_vertex_shader,
		NIRT_EXT_vertex_weighting,
		NIRT_EXT_x11_sync_object,
		NIRT_GREMEDY_frame_terminator,
		NIRT_GREMEDY_string_marker,
		NIRT_HP_convolution_border_modes,
		NIRT_HP_image_transform,
		NIRT_HP_occlusion_test,
		NIRT_HP_texture_lighting,
		NIRT_IBM_cull_vertex,
		NIRT_IBM_multimode_draw_arrays,
		NIRT_IBM_rasterpos_clip,
		NIRT_IBM_static_data,
		NIRT_IBM_texture_mirrored_repeat,
		NIRT_IBM_vertex_array_lists,
		NIRT_INGR_blend_func_separate,
		NIRT_INGR_color_clamp,
		NIRT_INGR_interlace_read,
		NIRT_INGR_palette_buffer,
		NIRT_INTEL_map_texture,
		NIRT_INTEL_parallel_arrays,
		NIRT_INTEL_texture_scissor,
		NIRT_KHR_debug,
		NIRT_KHR_texture_compression_astc_hdr,
		NIRT_KHR_texture_compression_astc_ldr,
		NIRT_MESA_pack_invert,
		NIRT_MESA_resize_buffers,
		NIRT_MESA_window_pos,
		NIRT_MESAX_texture_stack,
		NIRT_MESA_ycbcr_texture,
		NIRT_NVX_conditional_render,
		NIRT_NV_bindless_multi_draw_indirect,
		NIRT_NV_bindless_texture,
		NIRT_NV_blend_equation_advanced,
		NIRT_NV_blend_equation_advanced_coherent,
		NIRT_NV_blend_square,
		NIRT_NV_compute_program5,
		NIRT_NV_conditional_render,
		NIRT_NV_copy_depth_to_color,
		NIRT_NV_copy_image,
		NIRT_NV_deep_texture3D,
		NIRT_NV_depth_buffer_float,
		NIRT_NV_depth_clamp,
		NIRT_NV_draw_texture,
		NIRT_NV_evaluators,
		NIRT_NV_explicit_multisample,
		NIRT_NV_fence,
		NIRT_NV_float_buffer,
		NIRT_NV_fog_distance,
		NIRT_NV_fragment_program,
		NIRT_NV_fragment_program2,
		NIRT_NV_fragment_program4,
		NIRT_NV_fragment_program_option,
		NIRT_NV_framebuffer_multisample_coverage,
		NIRT_NV_geometry_program4,
		NIRT_NV_geometry_shader4,
		NIRT_NV_gpu_program4,
		NIRT_NV_gpu_program5,
		NIRT_NV_gpu_program5_mem_extended,
		NIRT_NV_gpu_shader5,
		NIRT_NV_half_float,
		NIRT_NV_light_max_exponent,
		NIRT_NV_multisample_coverage,
		NIRT_NV_multisample_filter_hint,
		NIRT_NV_occlusion_query,
		NIRT_NV_packed_depth_stencil,
		NIRT_NV_parameter_buffer_object,
		NIRT_NV_parameter_buffer_object2,
		NIRT_NV_path_rendering,
		NIRT_NV_pixel_data_range,
		NIRT_NV_point_sprite,
		NIRT_NV_present_video,
		NIRT_NV_primitive_restart,
		NIRT_NV_register_combiners,
		NIRT_NV_register_combiners2,
		NIRT_NV_shader_atomic_counters,
		NIRT_NV_shader_atomic_float,
		NIRT_NV_shader_buffer_load,
		NIRT_NV_shader_buffer_store,
		NIRT_NV_shader_storage_buffer_object,
		NIRT_NV_tessellation_program5,
		NIRT_NV_texgen_emboss,
		NIRT_NV_texgen_reflection,
		NIRT_NV_texture_barrier,
		NIRT_NV_texture_compression_vtc,
		NIRT_NV_texture_env_combine4,
		NIRT_NV_texture_expand_normal,
		NIRT_NV_texture_multisample,
		NIRT_NV_texture_rectangle,
		NIRT_NV_texture_shader,
		NIRT_NV_texture_shader2,
		NIRT_NV_texture_shader3,
		NIRT_NV_transform_feedback,
		NIRT_NV_transform_feedback2,
		NIRT_NV_vdpau_interop,
		NIRT_NV_vertex_array_range,
		NIRT_NV_vertex_array_range2,
		NIRT_NV_vertex_attrib_integer_64bit,
		NIRT_NV_vertex_buffer_unified_memory,
		NIRT_NV_vertex_program,
		NIRT_NV_vertex_program1_1,
		NIRT_NV_vertex_program2,
		NIRT_NV_vertex_program2_option,
		NIRT_NV_vertex_program3,
		NIRT_NV_vertex_program4,
		NIRT_NV_video_capture,
		NIRT_OES_byte_coordinates,
		NIRT_OES_compressed_paletted_texture,
		NIRT_OES_fixed_point,
		NIRT_OES_query_matrix,
		NIRT_OES_read_format,
		NIRT_OES_single_precision,
		NIRT_OML_interlace,
		NIRT_OML_resample,
		NIRT_OML_subsample,
		NIRT_PGI_misc_hints,
		NIRT_PGI_vertex_hints,
		NIRT_REND_screen_coordinates,
		NIRT_S3_s3tc,
		NIRT_SGI_color_matrix,
		NIRT_SGI_color_table,
		NIRT_SGI_texture_color_table,
		NIRT_SGIS_detail_texture,
		NIRT_SGIS_fog_function,
		NIRT_SGIS_generate_mipmap,
		NIRT_SGIS_multisample,
		NIRT_SGIS_pixel_texture,
		NIRT_SGIS_point_line_texgen,
		NIRT_SGIS_point_parameters,
		NIRT_SGIS_sharpen_texture,
		NIRT_SGIS_texture4D,
		NIRT_SGIS_texture_border_clamp,
		NIRT_SGIS_texture_color_mask,
		NIRT_SGIS_texture_edge_clamp,
		NIRT_SGIS_texture_filter4,
		NIRT_SGIS_texture_lod,
		NIRT_SGIS_texture_select,
		NIRT_SGIX_async,
		NIRT_SGIX_async_histogram,
		NIRT_SGIX_async_pixel,
		NIRT_SGIX_blend_alpha_minmax,
		NIRT_SGIX_calligraphic_fragment,
		NIRT_SGIX_clipmap,
		NIRT_SGIX_convolution_accuracy,
		NIRT_SGIX_depth_pass_instrument,
		NIRT_SGIX_depth_texture,
		NIRT_SGIX_flush_raster,
		NIRT_SGIX_fog_offset,
		NIRT_SGIX_fog_scale,
		NIRT_SGIX_fragment_lighting,
		NIRT_SGIX_framezoom,
		NIRT_SGIX_igloo_interface,
		NIRT_SGIX_instruments,
		NIRT_SGIX_interlace,
		NIRT_SGIX_ir_instrument1,
		NIRT_SGIX_list_priority,
		NIRT_SGIX_pixel_texture,
		NIRT_SGIX_pixel_tiles,
		NIRT_SGIX_polynomial_ffd,
		NIRT_SGIX_reference_plane,
		NIRT_SGIX_resample,
		NIRT_SGIX_scalebias_hint,
		NIRT_SGIX_shadow,
		NIRT_SGIX_shadow_ambient,
		NIRT_SGIX_sprite,
		NIRT_SGIX_subsample,
		NIRT_SGIX_tag_sample_buffer,
		NIRT_SGIX_texture_add_env,
		NIRT_SGIX_texture_coordinate_clamp,
		NIRT_SGIX_texture_lod_bias,
		NIRT_SGIX_texture_multi_buffer,
		NIRT_SGIX_texture_scale_bias,
		NIRT_SGIX_vertex_preclip,
		NIRT_SGIX_ycrcb,
		NIRT_SGIX_ycrcba,
		NIRT_SGIX_ycrcb_subsample,
		NIRT_SUN_convolution_border_modes,
		NIRT_SUN_global_alpha,
		NIRT_SUN_mesh_array,
		NIRT_SUN_slice_accum,
		NIRT_SUN_triangle_list,
		NIRT_SUN_vertex,
		NIRT_SUNX_constant_data,
		NIRT_WIN_phong_shading,
		NIRT_WIN_specular_fog,
		NIRT_NVX_gpu_memory_info,
		NIRT_OpenGL_Feature_Count
	};


	// constructor
	COpenGLExtensionHandler();

	// deferred initialization
	void initExtensions(bool stencilBuffer);

	const COpenGLCoreFeature& getFeature() const;

	//! queries the features of the driver, returns true if feature is available
	bool queryFeature(E_VIDEO_DRIVER_FEATURE feature) const;

	//! queries the features of the driver, returns true if feature is available
	bool queryOpenGLFeature(EOpenGLFeatures feature) const
	{
		return FeatureAvailable[feature];
	}

	//! show all features with availability
	void dump(ELOG_LEVEL logLevel) const;

	void dumpFramebufferFormats() const;

	// Some variables for properties
	bool StencilBuffer;
	bool TextureCompressionExtension;

	// Some non-boolean properties
	//! Maximum hardware lights supported
	u8 MaxLights;
	//! Maximal Anisotropy
	u8 MaxAnisotropy;
	//! Number of user clipplanes
	u8 MaxUserClipPlanes;
	//! Number of auxiliary buffers
	u8 MaxAuxBuffers;
	//! Optimal number of indices per meshbuffer
	u32 MaxIndices;
	//! Maximal texture dimension
	u32 MaxTextureSize;
	//! Maximal vertices handled by geometry shaders
	u32 MaxGeometryVerticesOut;
	//! Maximal LOD Bias
	f32 MaxTextureLODBias;
	//! Minimal and maximal supported thickness for lines without smoothing
	GLfloat DimAliasedLine[2];
	//! Minimal and maximal supported thickness for points without smoothing
	GLfloat DimAliasedPoint[2];
	//! Minimal and maximal supported thickness for lines with smoothing
	GLfloat DimSmoothedLine[2];
	//! Minimal and maximal supported thickness for points with smoothing
	GLfloat DimSmoothedPoint[2];

	//! OpenGL version as Integer: 100*Major+Minor, i.e. 2.1 becomes 201
	u16 Version;
	//! GLSL version as Integer: 100*Major+Minor
	u16 ShaderLanguageVersion;

	bool OcclusionQuerySupport;

	// Info needed for workarounds.
	bool IsAtiRadeonX;

	//! Workaround until direct state access with framebuffers is stable enough in drivers
	// https://devtalk.nvidia.com/default/topic/1030494/opengl/bug-amp-amp-spec-violation-checknamedframebufferstatus-returns-gl_framebuffer_incomplete_dimensions_ext-under-gl-4-5-core/
	// https://stackoverflow.com/questions/51304706/problems-with-attaching-textures-of-different-sizes-to-fbo
    static bool needsDSAFramebufferHack;

	// public access to the (loaded) extensions.
	// general functions
	void irrGlActiveTexture(GLenum texture);
	void irrGlClientActiveTexture(GLenum texture);
	void extGlPointParameterf(GLint loc, GLfloat f);
	void extGlPointParameterfv(GLint loc, const GLfloat *v);
	void extGlStencilFuncSeparate (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
	void extGlStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
	void irrGlCompressedTexImage2D(GLenum target, GLint level,
		GLenum internalformat, GLsizei width, GLsizei height,
		GLint border, GLsizei imageSize, const void* data);
	void irrGlCompressedTexSubImage2D(GLenum target, GLint level,
		GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
		GLenum format, GLsizei imageSize, const void* data);

	// shader programming
	void extGlGenPrograms(GLsizei n, GLuint *programs);
	void extGlBindProgram(GLenum target, GLuint program);
	void extGlProgramString(GLenum target, GLenum format, GLsizei len, const GLvoid *string);
	void extGlLoadProgram(GLenum target, GLuint id, GLsizei len, const GLubyte *string);
	void extGlDeletePrograms(GLsizei n, const GLuint *programs);
	void extGlProgramLocalParameter4fv(GLenum, GLuint, const GLfloat *);
	GLhandleARB extGlCreateShaderObject(GLenum shaderType);
	GLuint extGlCreateShader(GLenum shaderType);
	// note: Due to the type confusion between shader_objects and OpenGL 2.0
	// we have to add the ARB extension for proper method definitions in case
	// that handleARB and uint are the same type
	void extGlShaderSourceARB(GLhandleARB shader, GLsizei numOfStrings, const char **strings, const GLint *lenOfStrings);
	void extGlShaderSource(GLuint shader, GLsizei numOfStrings, const char **strings, const GLint *lenOfStrings);
	// note: Due to the type confusion between shader_objects and OpenGL 2.0
	// we have to add the ARB extension for proper method definitions in case
	// that handleARB and uint are the same type
	void extGlCompileShaderARB(GLhandleARB shader);
	void extGlCompileShader(GLuint shader);
	GLhandleARB extGlCreateProgramObject(void);
	GLuint extGlCreateProgram(void);
	void extGlAttachObject(GLhandleARB program, GLhandleARB shader);
	void extGlAttachShader(GLuint program, GLuint shader);
	void extGlLinkProgramARB(GLhandleARB program);
	// note: Due to the type confusion between shader_objects and OpenGL 2.0
	// we have to add the ARB extension for proper method definitions in case
	// that handleARB and uint are the same type
	void extGlLinkProgram(GLuint program);
	void extGlUseProgramObject(GLhandleARB prog);
	void irrGlUseProgram(GLuint prog);
	void extGlDeleteObject(GLhandleARB object);
	void extGlDeleteProgram(GLuint object);
	void extGlDeleteShader(GLuint shader);
	void extGlGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
	void extGlGetAttachedObjects(GLhandleARB program, GLsizei maxcount, GLsizei* count, GLhandleARB* shaders);
	void extGlGetInfoLog(GLhandleARB object, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
	void extGlGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
	void extGlGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
	void extGlGetObjectParameteriv(GLhandleARB object, GLenum type, GLint *param);
	void extGlGetShaderiv(GLuint shader, GLenum type, GLint *param);
	void extGlGetProgramiv(GLuint program, GLenum type, GLint *param);
	GLint extGlGetUniformLocationARB(GLhandleARB program, const char *name);
	GLint extGlGetUniformLocation(GLuint program, const char *name);
	void extGlUniform1fv(GLint loc, GLsizei count, const GLfloat *v);
	void extGlUniform2fv(GLint loc, GLsizei count, const GLfloat *v);
	void extGlUniform3fv(GLint loc, GLsizei count, const GLfloat *v);
	void extGlUniform4fv(GLint loc, GLsizei count, const GLfloat *v);
	void extGlUniform1bv(GLint loc, GLsizei count, const bool *v);
	void extGlUniform2bv(GLint loc, GLsizei count, const bool *v);
	void extGlUniform3bv(GLint loc, GLsizei count, const bool *v);
	void extGlUniform4bv(GLint loc, GLsizei count, const bool *v);
	void extGlUniform1iv(GLint loc, GLsizei count, const GLint *v);
	void extGlUniform2iv(GLint loc, GLsizei count, const GLint *v);
	void extGlUniform3iv(GLint loc, GLsizei count, const GLint *v);
	void extGlUniform4iv(GLint loc, GLsizei count, const GLint *v);
	void extGlUniform1uiv(GLint loc, GLsizei count, const GLuint *v);
	void extGlUniform2uiv(GLint loc, GLsizei count, const GLuint *v);
	void extGlUniform3uiv(GLint loc, GLsizei count, const GLuint *v);
	void extGlUniform4uiv(GLint loc, GLsizei count, const GLuint *v);
	void extGlUniformMatrix2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix2x3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix2x4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix3x2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix3x4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix4x2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix4x3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlUniformMatrix4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v);
	void extGlGetActiveUniformARB(GLhandleARB program, GLuint index, GLsizei maxlength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
	void extGlGetActiveUniform(GLuint program, GLuint index, GLsizei maxlength, GLsizei *length, GLint *size, GLenum *type, GLchar *name);

	// framebuffer objects
	void irrGlBindFramebuffer(GLenum target, GLuint framebuffer);
	void irrGlDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
	void irrGlGenFramebuffers(GLsizei n, GLuint *framebuffers);
	GLenum irrGlCheckFramebufferStatus(GLenum target);
	void irrGlFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void irrGlBindRenderbuffer(GLenum target, GLuint renderbuffer);
	void irrGlDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
	void irrGlGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
	void irrGlRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	void irrGlFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void irrGlGenerateMipmap(GLenum target);
	void irrGlActiveStencilFace(GLenum face);
	void irrGlDrawBuffer(GLenum mode);
	void irrGlDrawBuffers(GLsizei n, const GLenum *bufs);

	// vertex buffer object
	void extGlGenBuffers(GLsizei n, GLuint *buffers);
	void extGlBindBuffer(GLenum target, GLuint buffer);
	void extGlBufferData(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
	void extGlDeleteBuffers(GLsizei n, const GLuint *buffers);
	void extGlBufferSubData (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
	void extGlGetBufferSubData (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
	void *extGlMapBuffer (GLenum target, GLenum access);
	GLboolean extGlUnmapBuffer (GLenum target);
	GLboolean extGlIsBuffer (GLuint buffer);
	void extGlGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
	void extGlGetBufferPointerv (GLenum target, GLenum pname, GLvoid **params);
	void extGlProvokingVertex(GLenum mode);
	void extGlProgramParameteri(GLuint program, GLenum pname, GLint value);

	// occlusion query
	void extGlGenQueries(GLsizei n, GLuint *ids);
	void extGlDeleteQueries(GLsizei n, const GLuint *ids);
	GLboolean extGlIsQuery(GLuint id);
	void extGlBeginQuery(GLenum target, GLuint id);
	void extGlEndQuery(GLenum target);
	void extGlGetQueryiv(GLenum target, GLenum pname, GLint *params);
	void extGlGetQueryObjectiv(GLuint id, GLenum pname, GLint *params);
	void extGlGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params);

	// blend
	void irrGlBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	void irrGlBlendEquation(GLenum mode);

	// indexed
	void irrGlEnableIndexed(GLenum target, GLuint index);
	void irrGlDisableIndexed(GLenum target, GLuint index);
	void irrGlColorMaskIndexed(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	void irrGlBlendFuncIndexed(GLuint buf, GLenum src, GLenum dst);
	void irrGlBlendFuncSeparateIndexed(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	void irrGlBlendEquationIndexed(GLuint buf, GLenum mode);
	void irrGlBlendEquationSeparateIndexed(GLuint buf, GLenum modeRGB, GLenum modeAlpha);

    void extGlTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
    void extGlTextureStorage2D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    void extGlTextureStorage3D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	void extGlGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
    void extGlNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    void extGlTextureParameteri(GLuint texture, GLenum pname, GLint param);
	void extGlTextureParameterf(GLuint texture,	GLenum pname, GLfloat param);
	void extGlTextureParameteriv(GLuint texture, GLenum pname, const GLint* params);
	void extGlTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* params);
    void extGlCreateTextures(GLenum target, GLsizei n, GLuint* textures);
    void extGlCreateFramebuffers(GLsizei n, GLuint* framebuffers);
    void extGlBindTextures(GLuint first, GLsizei count, const GLuint *textures, const GLenum* targets);
    void extGlGenerateTextureMipmap(GLuint texture, GLenum target);


	// generic vsync setting method for several extensions
	void extGlSwapInterval(int interval);

	// the global feature array
	bool FeatureAvailable[NIRT_OpenGL_Feature_Count];

	protected:
		COpenGLCoreFeature Feature;

	#if defined(_NIRT_OPENGL_USE_EXTPOINTER_)
		PFNGLACTIVETEXTUREPROC pGlActiveTexture;
		PFNGLACTIVETEXTUREARBPROC pGlActiveTextureARB;
		PFNGLCLIENTACTIVETEXTUREARBPROC	pGlClientActiveTextureARB;
		PFNGLGENPROGRAMSARBPROC pGlGenProgramsARB;
		PFNGLGENPROGRAMSNVPROC pGlGenProgramsNV;
		PFNGLBINDPROGRAMARBPROC pGlBindProgramARB;
		PFNGLBINDPROGRAMNVPROC pGlBindProgramNV;
		PFNGLDELETEPROGRAMSARBPROC pGlDeleteProgramsARB;
		PFNGLDELETEPROGRAMSNVPROC pGlDeleteProgramsNV;
		PFNGLPROGRAMSTRINGARBPROC pGlProgramStringARB;
		PFNGLLOADPROGRAMNVPROC pGlLoadProgramNV;
		PFNGLPROGRAMLOCALPARAMETER4FVARBPROC pGlProgramLocalParameter4fvARB;
		PFNGLCREATESHADEROBJECTARBPROC pGlCreateShaderObjectARB;
		PFNGLSHADERSOURCEARBPROC pGlShaderSourceARB;
		PFNGLCOMPILESHADERARBPROC pGlCompileShaderARB;
		PFNGLCREATEPROGRAMOBJECTARBPROC pGlCreateProgramObjectARB;
		PFNGLATTACHOBJECTARBPROC pGlAttachObjectARB;
		PFNGLLINKPROGRAMARBPROC pGlLinkProgramARB;
		PFNGLUSEPROGRAMOBJECTARBPROC pGlUseProgramObjectARB;
		PFNGLDELETEOBJECTARBPROC pGlDeleteObjectARB;
		PFNGLCREATEPROGRAMPROC pGlCreateProgram;
		PFNGLUSEPROGRAMPROC pGlUseProgram;
		PFNGLDELETEPROGRAMPROC pGlDeleteProgram;
		PFNGLDELETESHADERPROC pGlDeleteShader;
		PFNGLGETATTACHEDOBJECTSARBPROC pGlGetAttachedObjectsARB;
		PFNGLGETATTACHEDSHADERSPROC pGlGetAttachedShaders;
		PFNGLCREATESHADERPROC pGlCreateShader;
		PFNGLSHADERSOURCEPROC pGlShaderSource;
		PFNGLCOMPILESHADERPROC pGlCompileShader;
		PFNGLATTACHSHADERPROC pGlAttachShader;
		PFNGLLINKPROGRAMPROC pGlLinkProgram;
		PFNGLGETINFOLOGARBPROC pGlGetInfoLogARB;
		PFNGLGETSHADERINFOLOGPROC pGlGetShaderInfoLog;
		PFNGLGETPROGRAMINFOLOGPROC pGlGetProgramInfoLog;
		PFNGLGETOBJECTPARAMETERIVARBPROC pGlGetObjectParameterivARB;
		PFNGLGETSHADERIVPROC pGlGetShaderiv;
		PFNGLGETSHADERIVPROC pGlGetProgramiv;
		PFNGLGETUNIFORMLOCATIONARBPROC pGlGetUniformLocationARB;
		PFNGLGETUNIFORMLOCATIONPROC pGlGetUniformLocation;
		PFNGLUNIFORM1FVARBPROC pGlUniform1fvARB;
		PFNGLUNIFORM2FVARBPROC pGlUniform2fvARB;
		PFNGLUNIFORM3FVARBPROC pGlUniform3fvARB;
		PFNGLUNIFORM4FVARBPROC pGlUniform4fvARB;
		PFNGLUNIFORM1IVARBPROC pGlUniform1ivARB;
		PFNGLUNIFORM2IVARBPROC pGlUniform2ivARB;
		PFNGLUNIFORM3IVARBPROC pGlUniform3ivARB;
		PFNGLUNIFORM4IVARBPROC pGlUniform4ivARB;
		PFNGLUNIFORM1UIVPROC pGlUniform1uiv;
		PFNGLUNIFORM2UIVPROC pGlUniform2uiv;
		PFNGLUNIFORM3UIVPROC pGlUniform3uiv;
		PFNGLUNIFORM4UIVPROC pGlUniform4uiv;
		PFNGLUNIFORMMATRIX2FVARBPROC pGlUniformMatrix2fvARB;
		PFNGLUNIFORMMATRIX2X3FVPROC pGlUniformMatrix2x3fv;
		PFNGLUNIFORMMATRIX2X4FVPROC pGlUniformMatrix2x4fv;
		PFNGLUNIFORMMATRIX3X2FVPROC pGlUniformMatrix3x2fv;
		PFNGLUNIFORMMATRIX3FVARBPROC pGlUniformMatrix3fvARB;
		PFNGLUNIFORMMATRIX3X4FVPROC pGlUniformMatrix3x4fv;
		PFNGLUNIFORMMATRIX4X2FVPROC pGlUniformMatrix4x2fv;
		PFNGLUNIFORMMATRIX4X3FVPROC pGlUniformMatrix4x3fv;
		PFNGLUNIFORMMATRIX4FVARBPROC pGlUniformMatrix4fvARB;
		PFNGLGETACTIVEUNIFORMARBPROC pGlGetActiveUniformARB;
		PFNGLGETACTIVEUNIFORMPROC pGlGetActiveUniform;
		PFNGLPOINTPARAMETERFARBPROC  pGlPointParameterfARB;
		PFNGLPOINTPARAMETERFVARBPROC pGlPointParameterfvARB;
		PFNGLSTENCILFUNCSEPARATEPROC pGlStencilFuncSeparate;
		PFNGLSTENCILOPSEPARATEPROC pGlStencilOpSeparate;
		PFNGLSTENCILFUNCSEPARATEATIPROC pGlStencilFuncSeparateATI;
		PFNGLSTENCILOPSEPARATEATIPROC pGlStencilOpSeparateATI;
		PFNGLCOMPRESSEDTEXIMAGE2DPROC pGlCompressedTexImage2D;
		PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC pGlCompressedTexSubImage2D;
		// ARB framebuffer object
		PFNGLBINDFRAMEBUFFERPROC pGlBindFramebuffer;
		PFNGLDELETEFRAMEBUFFERSPROC pGlDeleteFramebuffers;
		PFNGLGENFRAMEBUFFERSPROC pGlGenFramebuffers;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC pGlCheckFramebufferStatus;
		PFNGLFRAMEBUFFERTEXTURE2DPROC pGlFramebufferTexture2D;
		PFNGLBINDRENDERBUFFERPROC pGlBindRenderbuffer;
		PFNGLDELETERENDERBUFFERSPROC pGlDeleteRenderbuffers;
		PFNGLGENRENDERBUFFERSPROC pGlGenRenderbuffers;
		PFNGLRENDERBUFFERSTORAGEPROC pGlRenderbufferStorage;
		PFNGLFRAMEBUFFERRENDERBUFFERPROC pGlFramebufferRenderbuffer;
		PFNGLGENERATEMIPMAPPROC pGlGenerateMipmap;
		// EXT framebuffer object
		PFNGLBINDFRAMEBUFFEREXTPROC pGlBindFramebufferEXT;
		PFNGLDELETEFRAMEBUFFERSEXTPROC pGlDeleteFramebuffersEXT;
		PFNGLGENFRAMEBUFFERSEXTPROC pGlGenFramebuffersEXT;
		PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC pGlCheckFramebufferStatusEXT;
		PFNGLFRAMEBUFFERTEXTURE2DEXTPROC pGlFramebufferTexture2DEXT;
		PFNGLBINDRENDERBUFFEREXTPROC pGlBindRenderbufferEXT;
		PFNGLDELETERENDERBUFFERSEXTPROC pGlDeleteRenderbuffersEXT;
		PFNGLGENRENDERBUFFERSEXTPROC pGlGenRenderbuffersEXT;
		PFNGLRENDERBUFFERSTORAGEEXTPROC pGlRenderbufferStorageEXT;
		PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC pGlFramebufferRenderbufferEXT;
		PFNGLGENERATEMIPMAPEXTPROC pGlGenerateMipmapEXT;
		PFNGLACTIVESTENCILFACEEXTPROC pGlActiveStencilFaceEXT;
		PFNGLDRAWBUFFERSARBPROC pGlDrawBuffersARB;
		PFNGLDRAWBUFFERSATIPROC pGlDrawBuffersATI;
		PFNGLGENBUFFERSARBPROC pGlGenBuffersARB;
		PFNGLBINDBUFFERARBPROC pGlBindBufferARB;
		PFNGLBUFFERDATAARBPROC pGlBufferDataARB;
		PFNGLDELETEBUFFERSARBPROC pGlDeleteBuffersARB;
		PFNGLBUFFERSUBDATAARBPROC pGlBufferSubDataARB;
		PFNGLGETBUFFERSUBDATAARBPROC pGlGetBufferSubDataARB;
		PFNGLMAPBUFFERARBPROC pGlMapBufferARB;
		PFNGLUNMAPBUFFERARBPROC pGlUnmapBufferARB;
		PFNGLISBUFFERARBPROC pGlIsBufferARB;
		PFNGLGETBUFFERPARAMETERIVARBPROC pGlGetBufferParameterivARB;
		PFNGLGETBUFFERPOINTERVARBPROC pGlGetBufferPointervARB;
		PFNGLPROVOKINGVERTEXPROC pGlProvokingVertexARB;
		PFNGLPROVOKINGVERTEXEXTPROC pGlProvokingVertexEXT;
		PFNGLPROGRAMPARAMETERIARBPROC pGlProgramParameteriARB;
		PFNGLPROGRAMPARAMETERIEXTPROC pGlProgramParameteriEXT;
		PFNGLGENQUERIESARBPROC pGlGenQueriesARB;
		PFNGLDELETEQUERIESARBPROC pGlDeleteQueriesARB;
		PFNGLISQUERYARBPROC pGlIsQueryARB;
		PFNGLBEGINQUERYARBPROC pGlBeginQueryARB;
		PFNGLENDQUERYARBPROC pGlEndQueryARB;
		PFNGLGETQUERYIVARBPROC pGlGetQueryivARB;
		PFNGLGETQUERYOBJECTIVARBPROC pGlGetQueryObjectivARB;
		PFNGLGETQUERYOBJECTUIVARBPROC pGlGetQueryObjectuivARB;
		PFNGLGENOCCLUSIONQUERIESNVPROC pGlGenOcclusionQueriesNV;
		PFNGLDELETEOCCLUSIONQUERIESNVPROC pGlDeleteOcclusionQueriesNV;
		PFNGLISOCCLUSIONQUERYNVPROC pGlIsOcclusionQueryNV;
		PFNGLBEGINOCCLUSIONQUERYNVPROC pGlBeginOcclusionQueryNV;
		PFNGLENDOCCLUSIONQUERYNVPROC pGlEndOcclusionQueryNV;
		PFNGLGETOCCLUSIONQUERYIVNVPROC pGlGetOcclusionQueryivNV;
		PFNGLGETOCCLUSIONQUERYUIVNVPROC pGlGetOcclusionQueryuivNV;
		// Blend
		PFNGLBLENDFUNCSEPARATEEXTPROC pGlBlendFuncSeparateEXT;
		PFNGLBLENDFUNCSEPARATEPROC pGlBlendFuncSeparate;
		PFNGLBLENDEQUATIONEXTPROC pGlBlendEquationEXT;
		PFNGLBLENDEQUATIONPROC pGlBlendEquation;
		PFNGLBLENDEQUATIONSEPARATEEXTPROC pGlBlendEquationSeparateEXT;
		PFNGLBLENDEQUATIONSEPARATEPROC pGlBlendEquationSeparate;
		// Indexed
		PFNGLENABLEINDEXEDEXTPROC pGlEnableIndexedEXT;
		PFNGLDISABLEINDEXEDEXTPROC pGlDisableIndexedEXT;
		PFNGLCOLORMASKINDEXEDEXTPROC pGlColorMaskIndexedEXT;
		PFNGLBLENDFUNCINDEXEDAMDPROC pGlBlendFuncIndexedAMD;
		PFNGLBLENDFUNCIPROC pGlBlendFunciARB;
		PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC pGlBlendFuncSeparateIndexedAMD;
		PFNGLBLENDFUNCSEPARATEIPROC pGlBlendFuncSeparateiARB;
		PFNGLBLENDEQUATIONINDEXEDAMDPROC pGlBlendEquationIndexedAMD;
		PFNGLBLENDEQUATIONIPROC pGlBlendEquationiARB;
		PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC pGlBlendEquationSeparateIndexedAMD;
		PFNGLBLENDEQUATIONSEPARATEIPROC pGlBlendEquationSeparateiARB;

		// DSA
        PFNGLTEXTURESTORAGE2DPROC pGlTextureStorage2D;
        PFNGLTEXTURESTORAGE3DPROC pGlTextureStorage3D;
        PFNGLTEXTURESUBIMAGE2DPROC pGlTextureSubImage2D;
		PFNGLGETTEXTUREIMAGEPROC pGlGetTextureImage;
        PFNGLNAMEDFRAMEBUFFERTEXTUREPROC pGlNamedFramebufferTexture;
        PFNGLTEXTUREPARAMETERIPROC pGlTextureParameteri;
		PFNGLTEXTUREPARAMETERFPROC pGlTextureParameterf;
		PFNGLTEXTUREPARAMETERIVPROC pGlTextureParameteriv;
		PFNGLTEXTUREPARAMETERFVPROC pGlTextureParameterfv;

        PFNGLCREATETEXTURESPROC pGlCreateTextures;
        PFNGLCREATEFRAMEBUFFERSPROC pGlCreateFramebuffers;
        PFNGLBINDTEXTURESPROC pGlBindTextures;
        PFNGLGENERATETEXTUREMIPMAPPROC pGlGenerateTextureMipmap;
        // DSA with EXT or functions to simulate it
        PFNGLTEXTURESTORAGE2DEXTPROC pGlTextureStorage2DEXT;
        PFNGLTEXSTORAGE2DPROC pGlTexStorage2D;
        PFNGLTEXTURESTORAGE3DEXTPROC pGlTextureStorage3DEXT;
        PFNGLTEXSTORAGE3DPROC pGlTexStorage3D;
		PFNGLTEXTURESUBIMAGE2DEXTPROC pGlTextureSubImage2DEXT;
		PFNGLGETTEXTUREIMAGEEXTPROC pGlGetTextureImageEXT;
        PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC pGlNamedFramebufferTextureEXT;
        PFNGLFRAMEBUFFERTEXTUREPROC pGlFramebufferTexture;
        PFNGLGENERATETEXTUREMIPMAPEXTPROC pGlGenerateTextureMipmapEXT;

		#if defined(WGL_EXT_swap_control)
		PFNWGLSWAPINTERVALEXTPROC pWglSwapIntervalEXT;
		#endif
		#if defined(GLX_SGI_swap_control)
		PFNGLXSWAPINTERVALSGIPROC pGlxSwapIntervalSGI;
		#endif
		#if defined(GLX_EXT_swap_control)
		PFNGLXSWAPINTERVALEXTPROC pGlxSwapIntervalEXT;
		#endif
		#if defined(GLX_MESA_swap_control)
		PFNGLXSWAPINTERVALMESAPROC pGlxSwapIntervalMESA;
		#endif
	#endif
};

inline void COpenGLExtensionHandler::irrGlActiveTexture(GLenum texture)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlActiveTexture)
		pGlActiveTexture(texture);
	else if (pGlActiveTextureARB)
		pGlActiveTextureARB(texture);
#else
#ifdef GL_ARB_multitexture
		glActiveTextureARB(texture);
#else
		glActiveTexture(texture);
#endif
#endif
}

inline void COpenGLExtensionHandler::irrGlClientActiveTexture(GLenum texture)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlClientActiveTextureARB)
		pGlClientActiveTextureARB(texture);
#else
	glClientActiveTextureARB(texture);
#endif
}

inline void COpenGLExtensionHandler::extGlGenPrograms(GLsizei n, GLuint *programs)
{
	if (programs)
		memset(programs,0,n*sizeof(GLuint));
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenProgramsARB)
		pGlGenProgramsARB(n, programs);
	else if (pGlGenProgramsNV)
		pGlGenProgramsNV(n, programs);
#elif defined(GL_ARB_vertex_program) || defined(GL_ARB_fragment_program)
	glGenProgramsARB(n,programs);
#elif defined(GL_NV_vertex_program) || defined(GL_NV_fragment_program)
	glGenProgramsNV(n,programs);
#else
	os::Printer::log("glGenPrograms not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlBindProgram(GLenum target, GLuint program)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBindProgramARB)
		pGlBindProgramARB(target, program);
	else if (pGlBindProgramNV)
		pGlBindProgramNV(target, program);
#elif defined(GL_ARB_vertex_program) || defined(GL_ARB_fragment_program)
	glBindProgramARB(target, program);
#elif defined(GL_NV_vertex_program) || defined(GL_NV_fragment_program)
	glBindProgramNV(target, program);
#else
	os::Printer::log("glBindProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlProgramString(GLenum target, GLenum format, GLsizei len, const GLvoid *string)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlProgramStringARB)
		pGlProgramStringARB(target, format, len, string);
#elif defined(GL_ARB_vertex_program) || defined(GL_ARB_fragment_program)
	glProgramStringARB(target,format,len,string);
#else
	os::Printer::log("glProgramString not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlLoadProgram(GLenum target, GLuint id, GLsizei len, const GLubyte *string)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlLoadProgramNV)
		pGlLoadProgramNV(target, id, len, string);
#elif defined(GL_NV_vertex_program) || defined(GL_NV_fragment_program)
	glLoadProgramNV(target,id,len,string);
#else
	os::Printer::log("glLoadProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeletePrograms(GLsizei n, const GLuint *programs)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteProgramsARB)
		pGlDeleteProgramsARB(n, programs);
	else if (pGlDeleteProgramsNV)
		pGlDeleteProgramsNV(n, programs);
#elif defined(GL_ARB_vertex_program) || defined(GL_ARB_fragment_program)
	glDeleteProgramsARB(n,programs);
#elif defined(GL_NV_vertex_program) || defined(GL_NV_fragment_program)
	glDeleteProgramsNV(n,programs);
#else
	os::Printer::log("glDeletePrograms not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlProgramLocalParameter4fv(GLenum n, GLuint i, const GLfloat *f)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlProgramLocalParameter4fvARB)
		pGlProgramLocalParameter4fvARB(n,i,f);
#elif defined(GL_ARB_vertex_program) || defined(GL_ARB_fragment_program)
	glProgramLocalParameter4fvARB(n,i,f);
#else
	os::Printer::log("glProgramLocalParameter4fv not supported", ELL_ERROR);
#endif
}

inline GLhandleARB COpenGLExtensionHandler::extGlCreateShaderObject(GLenum shaderType)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCreateShaderObjectARB)
		return pGlCreateShaderObjectARB(shaderType);
#elif defined(GL_ARB_shader_objects)
	return glCreateShaderObjectARB(shaderType);
#else
	os::Printer::log("glCreateShaderObject not supported", ELL_ERROR);
#endif
	return 0;
}

inline GLuint COpenGLExtensionHandler::extGlCreateShader(GLenum shaderType)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCreateShader)
		return pGlCreateShader(shaderType);
#elif defined(GL_VERSION_2_0)
	return glCreateShader(shaderType);
#else
	os::Printer::log("glCreateShader not supported", ELL_ERROR);
#endif
	return 0;
}

inline void COpenGLExtensionHandler::extGlShaderSourceARB(GLhandleARB shader, GLsizei numOfStrings, const char **strings, const GLint *lenOfStrings)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlShaderSourceARB)
		pGlShaderSourceARB(shader, numOfStrings, strings, lenOfStrings);
#elif defined(GL_ARB_shader_objects)
	glShaderSourceARB(shader, numOfStrings, strings, (GLint *)lenOfStrings);
#else
	os::Printer::log("glShaderSource not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlShaderSource(GLuint shader, GLsizei numOfStrings, const char **strings, const GLint *lenOfStrings)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlShaderSource)
		pGlShaderSource(shader, numOfStrings, strings, lenOfStrings);
#elif defined(GL_VERSION_2_0)
	glShaderSource(shader, numOfStrings, strings, (GLint *)lenOfStrings);
#else
	os::Printer::log("glShaderSource not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlCompileShaderARB(GLhandleARB shader)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCompileShaderARB)
		pGlCompileShaderARB(shader);
#elif defined(GL_ARB_shader_objects)
	glCompileShaderARB(shader);
#else
	os::Printer::log("glCompileShader not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlCompileShader(GLuint shader)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCompileShader)
		pGlCompileShader(shader);
#elif defined(GL_VERSION_2_0)
	glCompileShader(shader);
#else
	os::Printer::log("glCompileShader not supported", ELL_ERROR);
#endif
}

inline GLhandleARB COpenGLExtensionHandler::extGlCreateProgramObject(void)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCreateProgramObjectARB)
		return pGlCreateProgramObjectARB();
#elif defined(GL_ARB_shader_objects)
	return glCreateProgramObjectARB();
#else
	os::Printer::log("glCreateProgramObject not supported", ELL_ERROR);
#endif
	return 0;
}

inline GLuint COpenGLExtensionHandler::extGlCreateProgram(void)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCreateProgram)
		return pGlCreateProgram();
#elif defined(GL_VERSION_2_0)
	return glCreateProgram();
#else
	os::Printer::log("glCreateProgram not supported", ELL_ERROR);
#endif
	return 0;
}

inline void COpenGLExtensionHandler::extGlAttachObject(GLhandleARB program, GLhandleARB shader)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlAttachObjectARB)
		pGlAttachObjectARB(program, shader);
#elif defined(GL_ARB_shader_objects)
	glAttachObjectARB(program, shader);
#else
	os::Printer::log("glAttachObject not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlAttachShader(GLuint program, GLuint shader)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlAttachShader)
		pGlAttachShader(program, shader);
#elif defined(GL_VERSION_2_0)
	glAttachShader(program, shader);
#else
	os::Printer::log("glAttachShader not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlLinkProgramARB(GLhandleARB program)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlLinkProgramARB)
		pGlLinkProgramARB(program);
#elif defined(GL_ARB_shader_objects)
	glLinkProgramARB(program);
#else
	os::Printer::log("glLinkProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlLinkProgram(GLuint program)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlLinkProgram)
		pGlLinkProgram(program);
#elif defined(GL_VERSION_2_0)
	glLinkProgram(program);
#else
	os::Printer::log("glLinkProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUseProgramObject(GLhandleARB prog)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUseProgramObjectARB)
		pGlUseProgramObjectARB(prog);
#elif defined(GL_ARB_shader_objects)
	glUseProgramObjectARB(prog);
#else
	os::Printer::log("glUseProgramObject not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlUseProgram(GLuint prog)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUseProgram)
		pGlUseProgram(prog);
#elif defined(GL_VERSION_2_0)
	glUseProgram(prog);
#else
	os::Printer::log("glUseProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeleteObject(GLhandleARB object)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteObjectARB)
		pGlDeleteObjectARB(object);
#elif defined(GL_ARB_shader_objects)
	glDeleteObjectARB(object);
#else
	os::Printer::log("glDeleteObject not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeleteProgram(GLuint object)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteProgram)
		pGlDeleteProgram(object);
#elif defined(GL_VERSION_2_0)
	glDeleteProgram(object);
#else
	os::Printer::log("glDeleteProgram not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeleteShader(GLuint shader)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteShader)
		pGlDeleteShader(shader);
#elif defined(GL_VERSION_2_0)
	glDeleteShader(shader);
#else
	os::Printer::log("glDeleteShader not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetAttachedObjects(GLhandleARB program, GLsizei maxcount, GLsizei* count, GLhandleARB* shaders)
{
	if (count)
		*count=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetAttachedObjectsARB)
		pGlGetAttachedObjectsARB(program, maxcount, count, shaders);
#elif defined(GL_ARB_shader_objects)
	glGetAttachedObjectsARB(program, maxcount, count, shaders);
#else
	os::Printer::log("glGetAttachedObjects not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
	if (count)
		*count=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetAttachedShaders)
		pGlGetAttachedShaders(program, maxcount, count, shaders);
#elif defined(GL_VERSION_2_0)
	glGetAttachedShaders(program, maxcount, count, shaders);
#else
	os::Printer::log("glGetAttachedShaders not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetInfoLog(GLhandleARB object, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog)
{
	if (length)
		*length=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetInfoLogARB)
		pGlGetInfoLogARB(object, maxLength, length, infoLog);
#elif defined(GL_ARB_shader_objects)
	glGetInfoLogARB(object, maxLength, length, infoLog);
#else
	os::Printer::log("glGetInfoLog not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog)
{
	if (length)
		*length=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetShaderInfoLog)
		pGlGetShaderInfoLog(shader, maxLength, length, infoLog);
#elif defined(GL_VERSION_2_0)
	glGetShaderInfoLog(shader, maxLength, length, infoLog);
#else
	os::Printer::log("glGetShaderInfoLog not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog)
{
	if (length)
		*length=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetProgramInfoLog)
		pGlGetProgramInfoLog(program, maxLength, length, infoLog);
#elif defined(GL_VERSION_2_0)
	glGetProgramInfoLog(program, maxLength, length, infoLog);
#else
	os::Printer::log("glGetProgramInfoLog not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetObjectParameteriv(GLhandleARB object, GLenum type, GLint *param)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetObjectParameterivARB)
		pGlGetObjectParameterivARB(object, type, param);
#elif defined(GL_ARB_shader_objects)
	glGetObjectParameterivARB(object, type, param);
#else
	os::Printer::log("glGetObjectParameteriv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetShaderiv(GLuint shader, GLenum type, GLint *param)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetShaderiv)
		pGlGetShaderiv(shader, type, param);
#elif defined(GL_VERSION_2_0)
	glGetShaderiv(shader, type, param);
#else
	os::Printer::log("glGetShaderiv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetProgramiv(GLuint program, GLenum type, GLint *param)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetProgramiv)
		pGlGetProgramiv(program, type, param);
#elif defined(GL_VERSION_2_0)
	glGetProgramiv(program, type, param);
#else
	os::Printer::log("glGetProgramiv not supported", ELL_ERROR);
#endif
}

inline GLint COpenGLExtensionHandler::extGlGetUniformLocationARB(GLhandleARB program, const char *name)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetUniformLocationARB)
		return pGlGetUniformLocationARB(program, name);
#elif defined(GL_ARB_shader_objects)
	return glGetUniformLocationARB(program, name);
#else
	os::Printer::log("glGetUniformLocation not supported", ELL_ERROR);
#endif
	return 0;
}

inline GLint COpenGLExtensionHandler::extGlGetUniformLocation(GLuint program, const char *name)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetUniformLocation)
		return pGlGetUniformLocation(program, name);
#elif defined(GL_VERSION_2_0)
	return glGetUniformLocation(program, name);
#else
	os::Printer::log("glGetUniformLocation not supported", ELL_ERROR);
#endif
	return 0;
}

inline void COpenGLExtensionHandler::extGlUniform1fv(GLint loc, GLsizei count, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform1fvARB)
		pGlUniform1fvARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform1fvARB(loc, count, v);
#else
	os::Printer::log("glUniform1fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform2fv(GLint loc, GLsizei count, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform2fvARB)
		pGlUniform2fvARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform2fvARB(loc, count, v);
#else
	os::Printer::log("glUniform2fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform3fv(GLint loc, GLsizei count, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform3fvARB)
		pGlUniform3fvARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform3fvARB(loc, count, v);
#else
	os::Printer::log("glUniform3fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform4fv(GLint loc, GLsizei count, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform4fvARB)
		pGlUniform4fvARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform4fvARB(loc, count, v);
#else
	os::Printer::log("glUniform4fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform1uiv(GLint loc, GLsizei count, const GLuint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform1uiv)
		pGlUniform1uiv(loc, count, v);
#elif defined(GL_VERSION_3_0)
	glUniform1uiv(loc, count, v);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform2uiv(GLint loc, GLsizei count, const GLuint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform2uiv)
		pGlUniform2uiv(loc, count, v);
#elif defined(GL_VERSION_3_0)
	glUniform2uiv(loc, count, v);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform3uiv(GLint loc, GLsizei count, const GLuint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform3uiv)
		pGlUniform3uiv(loc, count, v);
#elif defined(GL_VERSION_3_0)
	glUniform3uiv(loc, count, v);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform4uiv(GLint loc, GLsizei count, const GLuint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform4uiv)
		pGlUniform4uiv(loc, count, v);
#elif defined(GL_VERSION_3_0)
	glUniform4uiv(loc, count, v);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform1iv(GLint loc, GLsizei count, const GLint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform1ivARB)
		pGlUniform1ivARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform1ivARB(loc, count, v);
#else
	os::Printer::log("glUniform1iv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform2iv(GLint loc, GLsizei count, const GLint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform2ivARB)
		pGlUniform2ivARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform2ivARB(loc, count, v);
#else
	os::Printer::log("glUniform2iv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform3iv(GLint loc, GLsizei count, const GLint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform3ivARB)
		pGlUniform3ivARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform3ivARB(loc, count, v);
#else
	os::Printer::log("glUniform3iv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniform4iv(GLint loc, GLsizei count, const GLint *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniform4ivARB)
		pGlUniform4ivARB(loc, count, v);
#elif defined(GL_ARB_shader_objects)
	glUniform4ivARB(loc, count, v);
#else
	os::Printer::log("glUniform4iv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix2fvARB)
		pGlUniformMatrix2fvARB(loc, count, transpose, v);
#elif defined(GL_ARB_shader_objects)
	glUniformMatrix2fvARB(loc, count, transpose, v);
#else
	os::Printer::log("glUniformMatrix2fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix2x3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix2x3fv)
		pGlUniformMatrix2x3fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix2x3fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix2x4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix2x4fv)
		pGlUniformMatrix2x4fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix2x4fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix3x2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix3x2fv)
		pGlUniformMatrix3x2fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix3x2fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix3fvARB)
		pGlUniformMatrix3fvARB(loc, count, transpose, v);
#elif defined(GL_ARB_shader_objects)
	glUniformMatrix3fvARB(loc, count, transpose, v);
#else
	os::Printer::log("glUniformMatrix3fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix3x4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix3x4fv)
		pGlUniformMatrix3x4fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix3x4fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix4x2fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix4x2fv)
		pGlUniformMatrix4x2fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix4x2fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix4x3fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix4x3fv)
		pGlUniformMatrix4x3fv(loc, count, transpose, v);
	else
		os::Printer::log("glUniformMatrix4x3fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlUniformMatrix4fv(GLint loc, GLsizei count, GLboolean transpose, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUniformMatrix4fvARB)
		pGlUniformMatrix4fvARB(loc, count, transpose, v);
#elif defined(GL_ARB_shader_objects)
	glUniformMatrix4fvARB(loc, count, transpose, v);
#else
	os::Printer::log("glUniformMatrix4fv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetActiveUniformARB(GLhandleARB program,
		GLuint index, GLsizei maxlength, GLsizei *length,
		GLint *size, GLenum *type, GLcharARB *name)
{
	if (length)
		*length=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetActiveUniformARB)
		pGlGetActiveUniformARB(program, index, maxlength, length, size, type, name);
#elif defined(GL_ARB_shader_objects)
	glGetActiveUniformARB(program, index, maxlength, length, size, type, name);
#else
	os::Printer::log("glGetActiveUniform not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetActiveUniform(GLuint program,
		GLuint index, GLsizei maxlength, GLsizei *length,
		GLint *size, GLenum *type, GLchar *name)
{
	if (length)
		*length=0;
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetActiveUniform)
		pGlGetActiveUniform(program, index, maxlength, length, size, type, name);
#elif defined(GL_VERSION_2_0)
	glGetActiveUniform(program, index, maxlength, length, size, type, name);
#else
	os::Printer::log("glGetActiveUniform not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlPointParameterf(GLint loc, GLfloat f)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlPointParameterfARB)
		pGlPointParameterfARB(loc, f);
#elif defined(GL_ARB_point_parameters)
	glPointParameterfARB(loc, f);
#else
	os::Printer::log("glPointParameterf not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlPointParameterfv(GLint loc, const GLfloat *v)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlPointParameterfvARB)
		pGlPointParameterfvARB(loc, v);
#elif defined(GL_ARB_point_parameters)
	glPointParameterfvARB(loc, v);
#else
	os::Printer::log("glPointParameterfv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlStencilFuncSeparate (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlStencilFuncSeparate)
		pGlStencilFuncSeparate(frontfunc, backfunc, ref, mask);
	else if (pGlStencilFuncSeparateATI)
		pGlStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
#elif defined(GL_VERSION_2_0)
	glStencilFuncSeparate(frontfunc, backfunc, ref, mask);
#elif defined(GL_ATI_separate_stencil)
	glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
#else
	os::Printer::log("glStencilFuncSeparate not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlStencilOpSeparate)
		pGlStencilOpSeparate(face, fail, zfail, zpass);
	else if (pGlStencilOpSeparateATI)
		pGlStencilOpSeparateATI(face, fail, zfail, zpass);
#elif defined(GL_VERSION_2_0)
	glStencilOpSeparate(face, fail, zfail, zpass);
#elif defined(GL_ATI_separate_stencil)
	glStencilOpSeparateATI(face, fail, zfail, zpass);
#else
	os::Printer::log("glStencilOpSeparate not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width,
		GLsizei height, GLint border, GLsizei imageSize, const void* data)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCompressedTexImage2D)
		pGlCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
#elif defined(GL_ARB_texture_compression)
	glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
#else
	os::Printer::log("glCompressedTexImage2D not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
		GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCompressedTexSubImage2D)
		pGlCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
#elif defined(GL_ARB_texture_compression)
	glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
#else
	os::Printer::log("glCompressedTexSubImage2D not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBindFramebuffer(GLenum target, GLuint framebuffer)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBindFramebuffer)
		pGlBindFramebuffer(target, framebuffer);
	else if (pGlBindFramebufferEXT)
		pGlBindFramebufferEXT(target, framebuffer);
#elif defined(GL_ARB_framebuffer_object)
	glBindFramebuffer(target, framebuffer);
#elif defined(GL_EXT_framebuffer_object)
	glBindFramebufferEXT(target, framebuffer);
#else
	os::Printer::log("glBindFramebuffer not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteFramebuffers)
		pGlDeleteFramebuffers(n, framebuffers);
	else if (pGlDeleteFramebuffersEXT)
		pGlDeleteFramebuffersEXT(n, framebuffers);
#elif defined(GL_ARB_framebuffer_object)
	glDeleteFramebuffers(n, framebuffers);
#elif defined(GL_EXT_framebuffer_object)
	glDeleteFramebuffersEXT(n, framebuffers);
#else
	os::Printer::log("glDeleteFramebuffers not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	if (framebuffers)
		memset(framebuffers,0,n*sizeof(GLuint));
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenFramebuffers)
		pGlGenFramebuffers(n, framebuffers);
	else if (pGlGenFramebuffersEXT)
		pGlGenFramebuffersEXT(n, framebuffers);
#elif defined(GL_ARB_framebuffer_object)
	glGenFramebuffers(n, framebuffers);
#elif defined(GL_EXT_framebuffer_object)
	glGenFramebuffersEXT(n, framebuffers);
#else
	os::Printer::log("glGenFramebuffers not supported", ELL_ERROR);
#endif
}

inline GLenum COpenGLExtensionHandler::irrGlCheckFramebufferStatus(GLenum target)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlCheckFramebufferStatus)
		return pGlCheckFramebufferStatus(target);
	else if (pGlCheckFramebufferStatusEXT)
		return pGlCheckFramebufferStatusEXT(target);
	else
		return 0;
#elif defined(GL_ARB_framebuffer_object)
	return glCheckFramebufferStatus(target);
#elif defined(GL_EXT_framebuffer_object)
	return glCheckFramebufferStatusEXT(target);
#else
	os::Printer::log("glCheckFramebufferStatus not supported", ELL_ERROR);
	return 0;
#endif
}

inline void COpenGLExtensionHandler::irrGlFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlFramebufferTexture2D)
		pGlFramebufferTexture2D(target, attachment, textarget, texture, level);
	else if (pGlFramebufferTexture2DEXT)
		pGlFramebufferTexture2DEXT(target, attachment, textarget, texture, level);
#elif defined(GL_ARB_framebuffer_object)
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
#elif defined(GL_EXT_framebuffer_object)
	glFramebufferTexture2DEXT(target, attachment, textarget, texture, level);
#else
	os::Printer::log("glFramebufferTexture2D not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBindRenderbuffer)
		pGlBindRenderbuffer(target, renderbuffer);
	else if (pGlBindRenderbufferEXT)
		pGlBindRenderbufferEXT(target, renderbuffer);
#elif defined(GL_ARB_framebuffer_object)
	glBindRenderbuffer(target, renderbuffer);
#elif defined(GL_EXT_framebuffer_object)
	glBindRenderbufferEXT(target, renderbuffer);
#else
	os::Printer::log("glBindRenderbuffer not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteRenderbuffers)
		pGlDeleteRenderbuffers(n, renderbuffers);
	else if (pGlDeleteRenderbuffersEXT)
		pGlDeleteRenderbuffersEXT(n, renderbuffers);
#elif defined(GL_ARB_framebuffer_object)
	glDeleteRenderbuffers(n, renderbuffers);
#elif defined(GL_EXT_framebuffer_object)
	glDeleteRenderbuffersEXT(n, renderbuffers);
#else
	os::Printer::log("glDeleteRenderbuffers not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	if (renderbuffers)
		memset(renderbuffers,0,n*sizeof(GLuint));
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenRenderbuffers)
		pGlGenRenderbuffers(n, renderbuffers);
	else if (pGlGenRenderbuffersEXT)
		pGlGenRenderbuffersEXT(n, renderbuffers);
#elif defined(GL_ARB_framebuffer_object)
	glGenRenderbuffers(n, renderbuffers);
#elif defined(GL_EXT_framebuffer_object)
	glGenRenderbuffersEXT(n, renderbuffers);
#else
	os::Printer::log("glGenRenderbuffers not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlRenderbufferStorage)
		pGlRenderbufferStorage(target, internalformat, width, height);
	else if (pGlRenderbufferStorageEXT)
		pGlRenderbufferStorageEXT(target, internalformat, width, height);
#elif defined(GL_ARB_framebuffer_object)
	glRenderbufferStorage(target, internalformat, width, height);
#elif defined(GL_EXT_framebuffer_object)
	glRenderbufferStorageEXT(target, internalformat, width, height);
#else
	os::Printer::log("glRenderbufferStorage not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlFramebufferRenderbuffer)
		pGlFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	else if (pGlFramebufferRenderbufferEXT)
		pGlFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);
#elif defined(GL_ARB_framebuffer_object)
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
#elif defined(GL_EXT_framebuffer_object)
	glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);
#else
	os::Printer::log("glFramebufferRenderbuffer not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlGenerateMipmap(GLenum target)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenerateMipmap)
		pGlGenerateMipmap(target);
	else if (pGlGenerateMipmapEXT)
		pGlGenerateMipmapEXT(target);
#elif defined(GL_ARB_framebuffer_object)
	glGenerateMipmap(target);
#elif defined(GL_EXT_framebuffer_object)
	glGenerateMipmapEXT(target);
#else
	os::Printer::log("glGenerateMipmap not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlActiveStencilFace(GLenum face)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlActiveStencilFaceEXT)
		pGlActiveStencilFaceEXT(face);
#elif defined(GL_EXT_stencil_two_side)
	glActiveStencilFaceEXT(face);
#else
	os::Printer::log("glActiveStencilFace not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlDrawBuffer(GLenum mode)
{
	glDrawBuffer(mode);
}

inline void COpenGLExtensionHandler::irrGlDrawBuffers(GLsizei n, const GLenum *bufs)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDrawBuffersARB)
		pGlDrawBuffersARB(n, bufs);
	else if (pGlDrawBuffersATI)
		pGlDrawBuffersATI(n, bufs);
#elif defined(GL_ARB_draw_buffers)
	glDrawBuffersARB(n, bufs);
#elif defined(GL_ATI_draw_buffers)
	glDrawBuffersATI(n, bufs);
#else
	os::Printer::log("glDrawBuffers not supported", ELL_ERROR);
#endif
}


inline void COpenGLExtensionHandler::extGlGenBuffers(GLsizei n, GLuint *buffers)
{
	if (buffers)
		memset(buffers,0,n*sizeof(GLuint));
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenBuffersARB)
		pGlGenBuffersARB(n, buffers);
#elif defined(GL_ARB_vertex_buffer_object)
	glGenBuffers(n, buffers);
#else
	os::Printer::log("glGenBuffers not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlBindBuffer(GLenum target, GLuint buffer)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBindBufferARB)
		pGlBindBufferARB(target, buffer);
#elif defined(GL_ARB_vertex_buffer_object)
	glBindBuffer(target, buffer);
#else
	os::Printer::log("glBindBuffer not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlBufferData(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBufferDataARB)
		pGlBufferDataARB(target, size, data, usage);
#elif defined(GL_ARB_vertex_buffer_object)
	glBufferData(target, size, data, usage);
#else
	os::Printer::log("glBufferData not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeleteBuffers(GLsizei n, const GLuint *buffers)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteBuffersARB)
		pGlDeleteBuffersARB(n, buffers);
#elif defined(GL_ARB_vertex_buffer_object)
	glDeleteBuffers(n, buffers);
#else
	os::Printer::log("glDeleteBuffers not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBufferSubDataARB)
		pGlBufferSubDataARB(target, offset, size, data);
#elif defined(GL_ARB_vertex_buffer_object)
	glBufferSubData(target, offset, size, data);
#else
	os::Printer::log("glBufferSubData not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetBufferSubDataARB)
		pGlGetBufferSubDataARB(target, offset, size, data);
#elif defined(GL_ARB_vertex_buffer_object)
	glGetBufferSubData(target, offset, size, data);
#else
	os::Printer::log("glGetBufferSubData not supported", ELL_ERROR);
#endif
}

inline void *COpenGLExtensionHandler::extGlMapBuffer(GLenum target, GLenum access)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlMapBufferARB)
		return pGlMapBufferARB(target, access);
	return 0;
#elif defined(GL_ARB_vertex_buffer_object)
	return glMapBuffer(target, access);
#else
	os::Printer::log("glMapBuffer not supported", ELL_ERROR);
	return 0;
#endif
}

inline GLboolean COpenGLExtensionHandler::extGlUnmapBuffer(GLenum target)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlUnmapBufferARB)
		return pGlUnmapBufferARB(target);
	return false;
#elif defined(GL_ARB_vertex_buffer_object)
	return glUnmapBuffer(target);
#else
	os::Printer::log("glUnmapBuffer not supported", ELL_ERROR);
	return false;
#endif
}

inline GLboolean COpenGLExtensionHandler::extGlIsBuffer(GLuint buffer)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlIsBufferARB)
		return pGlIsBufferARB(buffer);
	return false;
#elif defined(GL_ARB_vertex_buffer_object)
	return glIsBuffer(buffer);
#else
	os::Printer::log("glDeleteBuffers not supported", ELL_ERROR);
	return false;
#endif
}

inline void COpenGLExtensionHandler::extGlGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetBufferParameterivARB)
		pGlGetBufferParameterivARB(target, pname, params);
#elif defined(GL_ARB_vertex_buffer_object)
	glGetBufferParameteriv(target, pname, params);
#else
	os::Printer::log("glGetBufferParameteriv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetBufferPointerv(GLenum target, GLenum pname, GLvoid **params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetBufferPointervARB)
		pGlGetBufferPointervARB(target, pname, params);
#elif defined(GL_ARB_vertex_buffer_object)
	glGetBufferPointerv(target, pname, params);
#else
	os::Printer::log("glGetBufferPointerv not supported", ELL_ERROR);
#endif
}


inline void COpenGLExtensionHandler::extGlProvokingVertex(GLenum mode)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_ARB_provoking_vertex] && pGlProvokingVertexARB)
		pGlProvokingVertexARB(mode);
	else if (FeatureAvailable[NIRT_EXT_provoking_vertex] && pGlProvokingVertexEXT)
		pGlProvokingVertexEXT(mode);
#elif defined(GL_ARB_provoking_vertex)
	glProvokingVertex(mode);
#elif defined(GL_EXT_provoking_vertex)
	glProvokingVertexEXT(mode);
#else
	os::Printer::log("glProvokingVertex not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlProgramParameteri(GLuint program, GLenum pname, GLint value)
{
#if defined(_NIRT_OPENGL_USE_EXTPOINTER_)
	if (queryFeature(EVDF_GEOMETRY_SHADER))
	{
		if (pGlProgramParameteriARB)
			pGlProgramParameteriARB(program, pname, value);
		else if (pGlProgramParameteriEXT)
			pGlProgramParameteriEXT(program, pname, value);
	}
#elif defined(GL_ARB_geometry_shader4)
	glProgramParameteriARB(program, pname, value);
#elif defined(GL_EXT_geometry_shader4)
	glProgramParameteriEXT(program, pname, value);
#elif defined(GL_NV_geometry_program4) || defined(GL_NV_geometry_shader4)
	glProgramParameteriNV(program, pname, value);
#else
	os::Printer::log("glProgramParameteri not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGenQueries(GLsizei n, GLuint *ids)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGenQueriesARB)
		pGlGenQueriesARB(n, ids);
	else if (pGlGenOcclusionQueriesNV)
		pGlGenOcclusionQueriesNV(n, ids);
#elif defined(GL_ARB_occlusion_query)
	glGenQueriesARB(n, ids);
#elif defined(GL_NV_occlusion_query)
	glGenOcclusionQueriesNV(n, ids);
#else
	os::Printer::log("glGenQueries not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlDeleteQueries(GLsizei n, const GLuint *ids)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlDeleteQueriesARB)
		pGlDeleteQueriesARB(n, ids);
	else if (pGlDeleteOcclusionQueriesNV)
		pGlDeleteOcclusionQueriesNV(n, ids);
#elif defined(GL_ARB_occlusion_query)
	glDeleteQueriesARB(n, ids);
#elif defined(GL_NV_occlusion_query)
	glDeleteOcclusionQueriesNV(n, ids);
#else
	os::Printer::log("glDeleteQueries not supported", ELL_ERROR);
#endif
}

inline GLboolean COpenGLExtensionHandler::extGlIsQuery(GLuint id)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlIsQueryARB)
		return pGlIsQueryARB(id);
	else if (pGlIsOcclusionQueryNV)
		return pGlIsOcclusionQueryNV(id);
	return false;
#elif defined(GL_ARB_occlusion_query)
	return glIsQueryARB(id);
#elif defined(GL_NV_occlusion_query)
	return glIsOcclusionQueryNV(id);
#else
	return false;
#endif
}

inline void COpenGLExtensionHandler::extGlBeginQuery(GLenum target, GLuint id)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBeginQueryARB)
		pGlBeginQueryARB(target, id);
	else if (pGlBeginOcclusionQueryNV)
		pGlBeginOcclusionQueryNV(id);
#elif defined(GL_ARB_occlusion_query)
	glBeginQueryARB(target, id);
#elif defined(GL_NV_occlusion_query)
	glBeginOcclusionQueryNV(id);
#else
	os::Printer::log("glBeginQuery not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlEndQuery(GLenum target)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlEndQueryARB)
		pGlEndQueryARB(target);
	else if (pGlEndOcclusionQueryNV)
		pGlEndOcclusionQueryNV();
#elif defined(GL_ARB_occlusion_query)
	glEndQueryARB(target);
#elif defined(GL_NV_occlusion_query)
	glEndOcclusionQueryNV();
#else
	os::Printer::log("glEndQuery not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetQueryiv(GLenum target, GLenum pname, GLint *params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetQueryivARB)
		pGlGetQueryivARB(target, pname, params);
#elif defined(GL_ARB_occlusion_query)
	glGetQueryivARB(target, pname, params);
#else
	os::Printer::log("glGetQueryivARB not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetQueryObjectivARB)
		pGlGetQueryObjectivARB(id, pname, params);
	else if (pGlGetOcclusionQueryivNV)
		pGlGetOcclusionQueryivNV(id, pname, params);
#elif defined(GL_ARB_occlusion_query)
	glGetQueryObjectivARB(id, pname, params);
#elif defined(GL_NV_occlusion_query)
	glGetOcclusionQueryivNV(id, pname, params);
#else
	os::Printer::log("glGetQueryObjectiv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlGetQueryObjectuivARB)
		pGlGetQueryObjectuivARB(id, pname, params);
	else if (pGlGetOcclusionQueryuivNV)
		pGlGetOcclusionQueryuivNV(id, pname, params);
#elif defined(GL_ARB_occlusion_query)
	glGetQueryObjectuivARB(id, pname, params);
#elif defined(GL_NV_occlusion_query)
	glGetOcclusionQueryuivNV(id, pname, params);
#else
	os::Printer::log("glGetQueryObjectuiv not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBlendFuncSeparate)
		pGlBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	else if (pGlBlendFuncSeparateEXT)
		pGlBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
#elif defined(GL_VERSION_1_4)
	glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
#elif defined(GL_EXT_blend_func_separate)
	glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
#else
	os::Printer::log("glBlendFuncSeparate not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendEquation(GLenum mode)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlBlendEquation)
		pGlBlendEquation(mode);
	else if (pGlBlendEquationEXT)
		pGlBlendEquationEXT(mode);
#elif defined(GL_VERSION_1_4)
	glBlendEquation(mode);
#elif defined(GL_EXT_blend_minmax)
	glBlendEquationEXT(mode);
#else
	os::Printer::log("glBlendEquation not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlEnableIndexed(GLenum target, GLuint index)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_EXT_draw_buffers2] && pGlEnableIndexedEXT)
		pGlEnableIndexedEXT(target, index);
#elif defined(GL_EXT_draw_buffers2)
	glEnableIndexedEXT(target, index);
#else
	os::Printer::log("glEnableIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlDisableIndexed(GLenum target, GLuint index)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_EXT_draw_buffers2] && pGlDisableIndexedEXT)
		pGlDisableIndexedEXT(target, index);
#elif defined(GL_EXT_draw_buffers2)
	glDisableIndexedEXT(target, index);
#else
	os::Printer::log("glDisableIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlColorMaskIndexed(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_EXT_draw_buffers2] && pGlColorMaskIndexedEXT)
		pGlColorMaskIndexedEXT(buf, r, g, b, a);
#elif defined(GL_EXT_draw_buffers2)
	glColorMaskIndexedEXT(buf, r, g, b, a);
#else
	os::Printer::log("glColorMaskIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendFuncIndexed(GLuint buf, GLenum src, GLenum dst)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_ARB_draw_buffers_blend] && pGlBlendFunciARB)
		pGlBlendFunciARB(buf, src, dst);
	else if (FeatureAvailable[NIRT_AMD_draw_buffers_blend] && pGlBlendFuncIndexedAMD)
		pGlBlendFuncIndexedAMD(buf, src, dst);
#elif defined(GL_ARB_draw_buffers_blend)
	glBlendFunciARB(buf, src, dst);
#elif defined(GL_AMD_draw_buffers_blend)
	glBlendFuncIndexedAMD(buf, src, dst);
#else
	os::Printer::log("glBlendFuncIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendFuncSeparateIndexed(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_ARB_draw_buffers_blend] && pGlBlendFuncSeparateiARB)
		pGlBlendFuncSeparateiARB(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	else if (FeatureAvailable[NIRT_AMD_draw_buffers_blend] && pGlBlendFuncSeparateIndexedAMD)
		pGlBlendFuncSeparateIndexedAMD(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
#elif defined(GL_ARB_draw_buffers_blend)
	glBlendFuncSeparateiARB(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
#elif defined(GL_AMD_draw_buffers_blend)
	glBlendFuncSeparateIndexedAMD(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
#else
	os::Printer::log("glBlendFuncSeparateIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendEquationIndexed(GLuint buf, GLenum mode)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_ARB_draw_buffers_blend] && pGlBlendEquationiARB)
		pGlBlendEquationiARB(buf, mode);
	else if (FeatureAvailable[NIRT_AMD_draw_buffers_blend] && pGlBlendEquationIndexedAMD)
		pGlBlendEquationIndexedAMD(buf, mode);
#elif defined(GL_ARB_draw_buffers_blend)
	glBlendEquationiARB(buf, mode);
#elif defined(GL_AMD_draw_buffers_blend)
	glBlendEquationIndexedAMD(buf, mode);
#else
	os::Printer::log("glBlendEquationIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::irrGlBlendEquationSeparateIndexed(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (FeatureAvailable[NIRT_ARB_draw_buffers_blend] && pGlBlendEquationSeparateiARB)
		pGlBlendEquationSeparateiARB(buf, modeRGB, modeAlpha);
	else if (FeatureAvailable[NIRT_AMD_draw_buffers_blend] && pGlBlendEquationSeparateIndexedAMD)
		pGlBlendEquationSeparateIndexedAMD(buf, modeRGB, modeAlpha);
#elif defined(GL_ARB_draw_buffers_blend)
	glBlendEquationSeparateiARB(buf, modeRGB, modeAlpha);
#elif defined(GL_AMD_draw_buffers_blend)
	glBlendEquationSeparateIndexedAMD(buf, modeRGB, modeAlpha);
#else
	os::Printer::log("glBlendEquationSeparateIndexed not supported", ELL_ERROR);
#endif
}

inline void COpenGLExtensionHandler::extGlTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels)
{
    if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureSubImage2D)
            pGlTextureSubImage2D(texture, level, xoffset, yoffset,width, height,format, type, pixels);
#elif defined(GL_VERSION_4_5)
        glTextureSubImage2D(texture, level, xoffset, yoffset,width, height,format, type, pixels);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else if (FeatureAvailable[NIRT_EXT_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureSubImage2DEXT)
            pGlTextureSubImage2DEXT(texture, target, level, xoffset, yoffset,width, height,format, type, pixels);
#elif defined(GL_EXT_direct_state_access)
        glTextureSubImage2DEXT(texture, target, level, xoffset, yoffset,width, height,format, type, pixels);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else
    {
        GLint bound;
        switch (target)
        {
#ifdef GL_VERSION_3_0
            case GL_TEXTURE_1D_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
                break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_1D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY_EXT, &bound);
                break;
#endif
            case GL_TEXTURE_2D:
                glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
                break;
#ifdef GL_VERSION_3_2
            case GL_TEXTURE_2D_MULTISAMPLE:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
                break;
#endif
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
                glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
                break;
#ifdef GL_VERSION_3_1
            case GL_TEXTURE_RECTANGLE:
                glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
                break;
#elif defined(GL_ARB_texture_rectangle)
			case GL_TEXTURE_RECTANGLE_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE_ARB, &bound);
                break;
#endif
            default:
                return;
        }
        glBindTexture(target, texture);
        glTexSubImage2D(target, level, xoffset, yoffset,width, height,format, type, pixels);
        glBindTexture(target, bound);
    }
}

inline void COpenGLExtensionHandler::extGlTextureStorage2D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
    if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureStorage2D)
            pGlTextureStorage2D(texture,levels,internalformat,width,height);
#elif defined(GL_VERSION_4_5)
        glTextureStorage2D(texture,levels,internalformat,width,height);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else if (FeatureAvailable[NIRT_EXT_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureStorage2DEXT)
            pGlTextureStorage2DEXT(texture,target,levels,internalformat,width,height);
#elif defined(GL_EXT_direct_state_access)
        glTextureStorage2DEXT(texture,target,levels,internalformat,width,height);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }

#if defined(GL_VERSION_4_2) || defined(_NIRT_OPENGL_USE_EXTPOINTER_)
    else
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    if (pGlTexStorage2D)
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    {
        GLint bound;
        switch (target)
        {
#ifdef GL_VERSION_3_0
            case GL_TEXTURE_1D_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
                break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_1D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY_EXT, &bound);
                break;
#endif
            case GL_TEXTURE_2D:
                glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
                break;
            case GL_TEXTURE_CUBE_MAP:
                glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
                break;
#ifdef GL_VERSION_3_1
            case GL_TEXTURE_RECTANGLE:
                glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
                break;
#elif defined(GL_ARB_texture_rectangle)
			case GL_TEXTURE_RECTANGLE_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE_ARB, &bound);
                break;
#endif
            default:
                return;
        }
        glBindTexture(target, texture);
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        pGlTexStorage2D(target,levels,internalformat,width,height);
#else
        glTexStorage2D(target,levels,internalformat,width,height);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
        glBindTexture(target, bound);
    }
#endif // GL_VERSION_4_2 || _NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlTextureStorage3D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
    if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureStorage3D)
            pGlTextureStorage3D(texture,levels,internalformat,width,height,depth);
#elif defined(GL_VERSION_4_5)
        glTextureStorage3D(texture,levels,internalformat,width,height,depth);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else if (FeatureAvailable[NIRT_EXT_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlTextureStorage3DEXT)
            pGlTextureStorage3DEXT(texture,target,levels,internalformat,width,height,depth);
#elif defined(GL_EXT_direct_state_access)
        glTextureStorage3DEXT(texture,target,levels,internalformat,width,height,depth);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
#if defined(GL_VERSION_4_2) || defined(_NIRT_OPENGL_USE_EXTPOINTER_)
    else
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    if (pGlTexStorage3D)
#endif // _NIRT_OPENGL_USE_EX TPOINTER_
    {
        GLint bound;
        switch (target)
        {
#ifdef GL_VERSION_3_0
            case GL_TEXTURE_2D_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
                break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_2D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY_EXT, &bound);
                break;
#endif
            case GL_TEXTURE_3D:
                glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
                break;
#ifdef GL_VERSION_4_0
            case GL_TEXTURE_CUBE_MAP_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
                break;
#elif defined(GL_ARB_texture_cube_map_array)
			case GL_TEXTURE_CUBE_MAP_ARRAY_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB, &bound);
				break;
#endif
            default:
                return;
        }
        glBindTexture(target, texture);
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        pGlTexStorage3D(target,levels,internalformat,width,height,depth);
#else
        glTexStorage3D(target,levels,internalformat,width,height,depth);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
        glBindTexture(target, bound);
    }
#endif // GL_VERSION_4_2 || _NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels)
{
	if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
	{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
		if (pGlGetTextureImage)
			pGlGetTextureImage(texture,level,format,type,bufSize,pixels);
#elif defined(GL_VERSION_4_5)
		glGetTextureImage(texture,level,format,type,bufSize,pixels);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
	}
	else if (FeatureAvailable[NIRT_EXT_direct_state_access])
	{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
		if (pGlGetTextureImageEXT)
			pGlGetTextureImageEXT(texture,target,level,format,type,pixels);
#elif defined(GL_EXT_direct_state_access)
		glGetTextureImageEXT(texture,target,level,format,type,pixels);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
	}
	else
	{
		GLint bound;
		switch (target)
		{
#ifdef GL_VERSION_3_0
			case GL_TEXTURE_2D_ARRAY:
				glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
				break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_2D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY_EXT, &bound);
                break;
#endif
			case GL_TEXTURE_3D:
				glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
				break;
#ifdef GL_VERSION_4_0
			case GL_TEXTURE_CUBE_MAP_ARRAY:
				glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
				break;
#elif defined(GL_ARB_texture_cube_map_array)
			case GL_TEXTURE_CUBE_MAP_ARRAY_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB, &bound);
				break;
#endif
			default:
				return;
		}
		glBindTexture(target, texture);
		glGetTexImage(target,level,format,type,pixels);
		glBindTexture(target, bound);
	}
}

inline void COpenGLExtensionHandler::extGlNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    if (!needsDSAFramebufferHack)
    {
        if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
        {
            pGlNamedFramebufferTexture(framebuffer, attachment, texture, level);
            return;
        }
        else if (FeatureAvailable[NIRT_EXT_direct_state_access])
        {
            pGlNamedFramebufferTextureEXT(framebuffer, attachment, texture, level);
            return;
        }
    }

    GLuint bound;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING,reinterpret_cast<GLint*>(&bound));

    if (bound!=framebuffer)
        pGlBindFramebuffer(GL_FRAMEBUFFER,framebuffer);
    pGlFramebufferTexture(GL_FRAMEBUFFER,attachment,texture,level);
    if (bound!=framebuffer)
        pGlBindFramebuffer(GL_FRAMEBUFFER,bound);
#endif
}

inline void COpenGLExtensionHandler::extGlTextureParameteri(GLuint texture, GLenum pname, GLint param)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    if (pGlTextureParameteri)
        pGlTextureParameteri(texture, pname, param);
#endif//_NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlTextureParameterf(GLuint texture, GLenum pname, GLfloat param)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlTextureParameterf)
		pGlTextureParameterf(texture, pname, param);
#endif//_NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlTextureParameteriv(GLuint texture, GLenum pname, const GLint* params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlTextureParameteriv)
		pGlTextureParameteriv(texture, pname, params);
#endif//_NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* params)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlTextureParameterfv)
		pGlTextureParameterfv(texture, pname, params);
#endif//_NIRT_OPENGL_USE_EXTPOINTER_
}

inline void COpenGLExtensionHandler::extGlCreateTextures(GLenum target, GLsizei n, GLuint* textures)
{
    if (Version>=405)
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlCreateTextures)
            pGlCreateTextures(target,n,textures);
        else if (textures)
            memset(textures,0,n*sizeof(GLuint));
#elif defined(GL_VERSION_4_5)
        glCreateTextures(target,n,textures);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else
    {
        glGenTextures(n,textures);
    }
}

inline void COpenGLExtensionHandler::extGlCreateFramebuffers(GLsizei n, GLuint* framebuffers)
{
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    if (!needsDSAFramebufferHack)
    {
        if (Version>=405)
        {
            pGlCreateFramebuffers(n, framebuffers);
            return;
        }
    }

    pGlGenFramebuffers(n, framebuffers);
#endif
}

inline void COpenGLExtensionHandler::extGlBindTextures(GLuint first, GLsizei count, const GLuint *textures, const GLenum* targets)
{
    const GLenum supportedTargets[] = { GL_TEXTURE_1D, GL_TEXTURE_2D // GL 1.x
                                        ,GL_TEXTURE_3D	// GL 2.x
#ifdef GL_VERSION_3_1
                                        ,GL_TEXTURE_RECTANGLE
#elif defined(GL_ARB_texture_rectangle)
										,GL_TEXTURE_RECTANGLE_ARB
#endif
                                        ,GL_TEXTURE_CUBE_MAP
#ifdef GL_VERSION_3_0
                                        ,GL_TEXTURE_1D_ARRAY,GL_TEXTURE_2D_ARRAY // GL 3.x
#elif GL_EXT_texture_array
										,GL_TEXTURE_1D_ARRAY_EXT,GL_TEXTURE_2D_ARRAY_EXT
#endif
#ifdef GL_VERSION_3_1
										,GL_TEXTURE_BUFFER
#elif defined(GL_ARB_texture_buffer_object)
										,GL_TEXTURE_BUFFER_ARB
#elif defined(GL_EXT_texture_buffer_object)
										,GL_TEXTURE_BUFFER_EXT
#endif
#ifdef GL_VERSION_4_0
                                        ,GL_TEXTURE_CUBE_MAP_ARRAY	// GL 4.x
#elif defined(GL_ARB_texture_cube_map_array)
										,GL_TEXTURE_CUBE_MAP_ARRAY_ARB
#endif
#ifdef GL_VERSION_3_2
                                        ,GL_TEXTURE_2D_MULTISAMPLE,GL_TEXTURE_2D_MULTISAMPLE_ARRAY
#endif
	};

    if (Version>=404||FeatureAvailable[NIRT_ARB_multi_bind])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlBindTextures)
            pGlBindTextures(first,count,textures);
#elif defined(GL_VERSION_4_4)
        glBindTextures(first,count,textures);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else
    {
        GLint activeTex = 0;
        glGetIntegerv(GL_ACTIVE_TEXTURE,&activeTex);

        for (GLsizei i=0; i<count; i++)
        {
            GLuint texture = textures ? textures[i]:0;

            GLuint unit = first+i;
			irrGlActiveTexture(GL_TEXTURE0 + unit);

            if (texture)
                glBindTexture(targets[i],texture);
            else
            {
                for (size_t j=0; j<sizeof(supportedTargets)/sizeof(GLenum); j++)
                    glBindTexture(supportedTargets[j],0);
            }
        }

		irrGlActiveTexture(activeTex);
    }
}

inline void COpenGLExtensionHandler::extGlGenerateTextureMipmap(GLuint texture, GLenum target)
{
    if (Version>=405 || FeatureAvailable[NIRT_ARB_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlGenerateTextureMipmap)
            pGlGenerateTextureMipmap(texture);
#elif defined(GL_VERSION_4_5)
        glGenerateTextureMipmap(texture);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
    else if (FeatureAvailable[NIRT_EXT_direct_state_access])
    {
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        if (pGlGenerateTextureMipmapEXT)
            pGlGenerateTextureMipmapEXT(texture,target);
#elif defined(GL_EXT_direct_state_access)
        glGenerateTextureMipmapEXT(texture,target);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    }
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
    else if (pGlGenerateMipmap)
#else
    else
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
    {
        GLint bound;
        switch (target)
        {
            case GL_TEXTURE_1D:
                glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
                break;
#ifdef GL_VERSION_3_0
            case GL_TEXTURE_1D_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
                break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_1D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY_EXT, &bound);
                break;
#endif
            case GL_TEXTURE_2D:
                glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
                break;
#ifdef GL_VERSION_3_0
            case GL_TEXTURE_2D_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
                break;
#elif GL_EXT_texture_array
			case GL_TEXTURE_2D_ARRAY_EXT:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY_EXT, &bound);
                break;
#endif
#ifdef GL_VERSION_3_2
            case GL_TEXTURE_2D_MULTISAMPLE:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
                break;
            case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &bound);
                break;
#endif
            case GL_TEXTURE_3D:
                glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
                break;
#ifdef GL_VERSION_3_1
            case GL_TEXTURE_BUFFER:
                glGetIntegerv(GL_TEXTURE_BINDING_BUFFER, &bound);
                break;
#elif defined(GL_ARB_texture_buffer_object)
			case GL_TEXTURE_BUFFER_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_BUFFER_ARB, &bound);
				break;
#elif defined(GL_EXT_texture_buffer_object)
			case GL_TEXTURE_BUFFER_EXT:
				glGetIntegerv(GL_TEXTURE_BINDING_BUFFER_EXT, &bound);
				break;
#endif
            case GL_TEXTURE_CUBE_MAP:
                glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
                break;
#ifdef GL_VERSION_4_0
            case GL_TEXTURE_CUBE_MAP_ARRAY:
                glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
                break;
#elif defined(GL_ARB_texture_cube_map_array)
			case GL_TEXTURE_CUBE_MAP_ARRAY_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB, &bound);
				break;
#endif
#ifdef GL_VERSION_3_1
            case GL_TEXTURE_RECTANGLE:
                glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
                break;
#elif defined(GL_ARB_texture_rectangle)
			case GL_TEXTURE_RECTANGLE_ARB:
				glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE_ARB, &bound);
                break;
#endif
            default:
                os::Printer::log("DevSH would like to ask you what are you doing!!??\n",ELL_ERROR);
                return;
        }
        glBindTexture(target, texture);
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
        pGlGenerateMipmap(target);
#else
        glGenerateMipmap(target);
#endif // _NIRT_OPENGL_USE_EXTPOINTER_
        glBindTexture(target, bound);
    }
}

inline void COpenGLExtensionHandler::extGlSwapInterval(int interval)
{
	// we have wglext, so try to use that
#if defined(_NIRT_WINDOWS_API_) && defined(_NIRT_COMPILE_WITH_WINDOWS_DEVICE_)
#ifdef WGL_EXT_swap_control
	if (pWglSwapIntervalEXT)
		pWglSwapIntervalEXT(interval);
#endif
#endif
#ifdef _NIRT_COMPILE_WITH_X11_DEVICE_
	//TODO: Check GLX_EXT_swap_control and GLX_MESA_swap_control
#ifdef GLX_SGI_swap_control
	// does not work with interval==0
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (interval && pGlxSwapIntervalSGI)
		pGlxSwapIntervalSGI(interval);
#else
	if (interval)
		glXSwapIntervalSGI(interval);
#endif
#elif defined(GLX_EXT_swap_control)
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	Display *dpy = glXGetCurrentDisplay();
	GLXDrawable drawable = glXGetCurrentDrawable();

	if (pGlxSwapIntervalEXT)
		pGlxSwapIntervalEXT(dpy, drawable, interval);
#else
	pGlXSwapIntervalEXT(dpy, drawable, interval);
#endif
#elif defined(GLX_MESA_swap_control)
#ifdef _NIRT_OPENGL_USE_EXTPOINTER_
	if (pGlxSwapIntervalMESA)
		pGlxSwapIntervalMESA(interval);
#else
	pGlXSwapIntervalMESA(interval);
#endif
#endif
#endif
}


}
}

#endif

#endif
