/* -*- c++ -*- */
/*
 * Copyright 2020 gr-tutorials author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "adder_impl.h"

namespace gr
{
namespace tutorials
{
template<class T>
typename adder<T>::sptr
adder<T>::make()
{
    return gnuradio::get_initial_sptr
            (new adder_impl<T>());
}


/*
 * The private constructor
 */
template<class T>
adder_impl<T>::adder_impl()
        : gr::sync_block("adder",
                         gr::io_signature::make(2, 2, sizeof(T)),
                         gr::io_signature::make(1, 1, sizeof(T)))
{}

/*
 * Our virtual destructor.
 */
template<class T>
adder_impl<T>::~adder_impl()
{
}

template<class T>
int
adder_impl<T>::work(int noutput_items,
                 gr_vector_const_void_star &input_items,
                 gr_vector_void_star &output_items)
{
    // Initialize a pointer for each input and output port
    // Since we're adding two input streams, we need a pointer for each
    const T* in1 = reinterpret_cast<const T *>(input_items[0]);
    const T* in2 = reinterpret_cast<const T *>(input_items[1]);
    T* out = reinterpret_cast<T*>(output_items[0]);

    // Add the inputs and output the result
    for (int i = 0; i < noutput_items; i++) {
        out[i] = in1[i] + in2[i];
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

template class adder<gr_complex>;
template class adder<float>;
template class adder<int>;
} /* namespace tutorials */
} /* namespace gr */

