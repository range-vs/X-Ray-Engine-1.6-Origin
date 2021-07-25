
namespace nv {

    struct BlockDXT5;
    class Vector4;

    float compress_dxt5_rgbm(const Vector4 input_colors[16], const float input_weights[16], float min_m, BlockDXT5 * output);
    float compress_etc2_rgbm(Vector4 input_colors[16], float input_weights[16], float min_m, void * output);
}
