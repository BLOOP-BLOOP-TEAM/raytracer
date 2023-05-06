/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Skybox
*/

#include "Skybox.hpp"

Raytracer::Skybox::Skybox(const std::string &filename) {
    load(filename);
}

Component::Color Raytracer::Skybox::getColor(const Component::Vector3f &direction) const
{
    // Convertir la direction en coordonnées de texture
    double u = 0.5 + std::atan2(direction.z, direction.x) / (2 * M_PI);
    double v = 0.5 - std::asin(direction.y) / M_PI;

    // Interpoler la couleur de la skybox en fonction des coordonnées de texture
    int x = static_cast<int>(u * _skyboxWidth);
    int y = static_cast<int>(v * _skyboxHeight);
    int index = y * _skyboxWidth + x;

    // Retourner la couleur correspondante de la skybox
    return _skyboxData[index];
}

void Raytracer::Skybox::load(const std::string &filename) {
    {
//        FILE *infile;
//        if ((infile = fopen(filename.c_str(), "rb")) == NULL) {
//            std::cerr << "Can't open " << filename << std::endl;
//            return;
//        }
//
//        jpeg_decompress_struct cinfo;
//        jpeg_error_mgr jerr;
//        cinfo.err = jpeg_std_error(&jerr);
//        jpeg_create_decompress(&cinfo);
//        jpeg_stdio_src(&cinfo, infile);
//        jpeg_read_header(&cinfo, TRUE);
//        jpeg_start_decompress(&cinfo);
//
//        _skyboxWidth = cinfo.output_width;
//        _skyboxHeight = cinfo.output_height;
//
//        int row_stride = cinfo.output_width * cinfo.output_components;
//        JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);
//
//        _skyboxData.resize(_skyboxWidth * _skyboxHeight);
//
//        int y = 0;
//        while (cinfo.output_scanline < cinfo.output_height) {
//            jpeg_read_scanlines(&cinfo, buffer, 1);
//            for (unsigned int x = 0; x < cinfo.output_width; ++x) {
//                _skyboxData[y * _skyboxWidth + x] = Component::Color(
//                        buffer[0][x * cinfo.output_components + 0],
//                        buffer[0][x * cinfo.output_components + 1],
//                        buffer[0][x * cinfo.output_components + 2]
//                );
//            }
//            ++y;
//        }
//
//        jpeg_finish_decompress(&cinfo);
//        jpeg_destroy_decompress(&cinfo);
//
//        fclose(infile);
    }
}
