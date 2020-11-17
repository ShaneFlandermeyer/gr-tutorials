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

#ifndef INCLUDED_TUTORIALS_ADDER_IMPL_H
#define INCLUDED_TUTORIALS_ADDER_IMPL_H

#include <tutorials/adder.h>

namespace gr
{
namespace tutorials
{

template<class T>
class adder_impl : public adder<T>
{
private:
    // Nothing to declare in this block.

public:
    adder_impl();

    ~adder_impl();

    // Where all the action really happens
    int work(
            int noutput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items
    );
};

} // namespace tutorials
} // namespace gr

#endif /* INCLUDED_TUTORIALS_ADDER_IMPL_H */

