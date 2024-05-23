/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savei.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:46:48 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 06:00:15 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h" 

void write_bmp_header(int fd, int filesize, int width, int height) {
    unsigned char header[54] = {
        0x42, 0x4D,       // Signature 'BM'
        0, 0, 0, 0,       // File size in bytes
        0, 0, 0, 0,       // Reserved
        54, 0, 0, 0,      // Offset to start of pixel data
        40, 0, 0, 0,      // Info header size
        0, 0, 0, 0,       // Width
        0, 0, 0, 0,       // Height
        1, 0,             // Planes
        24, 0,            // Bits per pixel (24 for RGB)
        0, 0, 0, 0,       // Compression (0 for no compression)
        0, 0, 0, 0,       // Image size (can be 0 for uncompressed)
        0, 0, 0, 0,       // X pixels per meter
        0, 0, 0, 0,       // Y pixels per meter
        0, 0, 0, 0,       // Total colors
        0, 0, 0, 0        // Important colors
    };

    header[2] = (unsigned char)(filesize);
    header[3] = (unsigned char)(filesize >> 8);
    header[4] = (unsigned char)(filesize >> 16);
    header[5] = (unsigned char)(filesize >> 24);

    header[18] = (unsigned char)(width);
    header[19] = (unsigned char)(width >> 8);
    header[20] = (unsigned char)(width >> 16);
    header[21] = (unsigned char)(width >> 24);

    header[22] = (unsigned char)(height);
    header[23] = (unsigned char)(height >> 8);
    header[24] = (unsigned char)(height >> 16);
    header[25] = (unsigned char)(height >> 24);

    write(fd, header, 54);
}

void write_pixel_data(int fd, unsigned char *data, int width, int height, int line_length) {
    for (int y = height - 1; y >= 0; y--) {
        write(fd, data + y * line_length, width * 3);
    }
}

void save_image_to_bmp(char *filename, unsigned char *data, int width, int height, int line_length) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        return;
    }

    int filesize = 54 + (3 * width * height);
    write_bmp_header(fd, filesize, width, height);
    write_pixel_data(fd, data, width, height, line_length);

    close(fd);
}


void handle_save_bmp(var_t *fractol) {
    int width = X;
    int height = Y;
    int bytes_per_pixel = 4; // mlx_get_data_addr returns BGRA format
    int line_length = fractol->img.line_length;

    // Prepare pixel data buffer
    unsigned char *data = malloc(width * height * 3); // BMP expects RGB
    if (!data) {
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_offset = (y * line_length) + (x * bytes_per_pixel);
            int dest_offset = (y * width + x) * 3;
            data[dest_offset + 0] = fractol->img.addr[src_offset + 0]; // Blue
            data[dest_offset + 1] = fractol->img.addr[src_offset + 1]; // Green
            data[dest_offset + 2] = fractol->img.addr[src_offset + 2]; // Red
        }
    }

    save_image_to_bmp("fractal_output.bmp", data, width, height, width * 3);

    free(data);
}