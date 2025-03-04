/*
 * Copyright (c) 2025 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://edgeimpulse.com/legal/terms-of-service) or Enterprise Terms of
 * Service (https://edgeimpulse.com/legal/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */

#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

/**
 * @file
 *  Auto-generated complete impulse definitions. The ei_impulse_handle_t should
 *  be passed to ei_run_classifier() function to use this specific impulse.
 *  This file should only be included in ei_run_classifier.h file.
 */

#include <stdint.h>
#include "model_metadata.h"
#include "anomaly_metadata.h"
#include "tflite-model/tflite_learn_35_compiled.h"

#include "edge-impulse-sdk/classifier/ei_model_types.h"
#include "edge-impulse-sdk/classifier/inferencing_engines/engines.h"

const char* ei_classifier_inferencing_categories[] = { "idle", "snake", "updown", "wave" };

EI_CLASSIFIER_DSP_AXES_INDEX_TYPE ei_dsp_config_31_axes[] = { 0, 1, 2 };
const uint32_t ei_dsp_config_31_axes_size = 3;
ei_dsp_config_spectral_analysis_t ei_dsp_config_31 = {
    31, // uint32_t blockId
    4, // int implementationVersion
    3, // int length of axes
    1.0f, // float scale-axes
    1, // int input-decimation-ratio
    "low", // select filter-type
    8.0f, // float filter-cutoff
    6, // int filter-order
    "FFT", // select analysis-type
    64, // int fft-length
    3, // int spectral-peaks-count
    0.1f, // float spectral-peaks-threshold
    "0.1, 0.5, 1.0, 2.0, 5.0", // string spectral-power-edges
    true, // boolean do-log
    true, // boolean do-fft-overlap
    1, // int wavelet-level
    "db4", // select wavelet
    false // boolean extra-low-freq
};

const uint8_t ei_dsp_blocks_size = 1;
ei_model_dsp_t ei_dsp_blocks[ei_dsp_blocks_size] = {
    { // DSP block 31
        31,
        39, // output size
        &extract_spectral_analysis_features, // DSP function pointer
        (void*)&ei_dsp_config_31, // pointer to config struct
        ei_dsp_config_31_axes, // array of offsets into the input stream, one for each axis
        ei_dsp_config_31_axes_size, // number of axes
        1, // version
        nullptr, // factory function
    }
};
const ei_config_tflite_eon_graph_t ei_config_tflite_graph_35 = {
    .implementation_version = 1,
    .model_init = &tflite_learn_35_init,
    .model_invoke = &tflite_learn_35_invoke,
    .model_reset = &tflite_learn_35_reset,
    .model_input = &tflite_learn_35_input,
    .model_output = &tflite_learn_35_output,
};


const ei_learning_block_config_tflite_graph_t ei_learning_block_config_35 = {
    .implementation_version = 1,
    .classification_mode = EI_CLASSIFIER_CLASSIFICATION_MODE_CLASSIFICATION,
    .block_id = 35,
    .object_detection = 0,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_UNKNOWN,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .threshold = 0,
    .quantized = 1,
    .compiled = 1,
    .graph_config = (void*)&ei_config_tflite_graph_35
};

const ei_learning_block_config_anomaly_kmeans_t ei_learning_block_config_41 = {
    .implementation_version = 1,
    .classification_mode = EI_CLASSIFIER_CLASSIFICATION_MODE_ANOMALY_KMEANS,
    .anom_axis = ei_classifier_anom_axes,
    .anom_axes_size = 6,
    .anom_clusters = ei_classifier_anom_clusters,
    .anom_cluster_count = 32,
    .anom_scale = ei_classifier_anom_scale,
    .anom_mean = ei_classifier_anom_mean,
};

const uint8_t ei_learning_blocks_size = 2;
const uint32_t ei_learning_block_35_inputs[1] = { 31 };
const uint8_t ei_learning_block_35_inputs_size = 1;
const uint32_t ei_learning_block_41_inputs[1] = { 31 };
const uint8_t ei_learning_block_41_inputs_size = 1;
const ei_learning_block_t ei_learning_blocks[ei_learning_blocks_size] = {
    {
        35,
        false,
        &run_nn_inference,
        (void*)&ei_learning_block_config_35,
        EI_CLASSIFIER_IMAGE_SCALING_NONE,
        ei_learning_block_35_inputs,
        ei_learning_block_35_inputs_size,
        4
    },
    {
        41,
        false,
        &run_kmeans_anomaly,
        (void*)&ei_learning_block_config_41,
        EI_CLASSIFIER_IMAGE_SCALING_NONE,
        ei_learning_block_41_inputs,
        ei_learning_block_41_inputs_size,
        1
    },
};


const ei_object_detection_nms_config_t ei_object_detection_nms = {
    0.0f, /* NMS confidence threshold */
    0.2f  /* NMS IOU threshold */
};

const ei_impulse_t impulse_618302_0 = {
    .project_id = 618302,
    .project_owner = "Milorad Cvjetkovic",
    .project_name = "Tutorial: Continuous motion recognition",
    .impulse_id = 1,
    .impulse_name = "Time series data, Spectral Analysis, Classification, Anomaly Detection (K-means)",
    .deploy_version = 162,

    .nn_input_frame_size = 39,
    .raw_sample_count = 125,
    .raw_samples_per_frame = 3,
    .dsp_input_frame_size = 125 * 3,
    .input_width = 0,
    .input_height = 0,
    .input_frames = 0,
    .interval_ms = 16,
    .frequency = 62.5,
    .dsp_blocks_size = ei_dsp_blocks_size,
    .dsp_blocks = ei_dsp_blocks,
    
    .object_detection_count = 0,
    .fomo_output_size = 0,

    
    .visual_ad_grid_size_x = 0,
    .visual_ad_grid_size_y = 0,
    
    .tflite_output_features_count = 4,
    .learning_blocks_size = ei_learning_blocks_size,
    .learning_blocks = ei_learning_blocks,

    .postprocessing_blocks_size = 0,
    .postprocessing_blocks = nullptr,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .sensor = EI_CLASSIFIER_SENSOR_ACCELEROMETER,
    .fusion_string = "accX + accY + accZ",
    .slice_size = (125/4),
    .slices_per_model_window = 4,

    .has_anomaly = EI_ANOMALY_TYPE_KMEANS,
    .label_count = 4,
    .categories = ei_classifier_inferencing_categories,
    .object_detection_nms = ei_object_detection_nms
};

ei_impulse_handle_t impulse_handle_618302_0 = ei_impulse_handle_t( &impulse_618302_0 );
ei_impulse_handle_t& ei_default_impulse = impulse_handle_618302_0;

#endif // _EI_CLASSIFIER_MODEL_VARIABLES_H_
