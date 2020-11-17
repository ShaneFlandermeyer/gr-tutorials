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

#ifndef INCLUDED_TUTORIALS_ADDER_H
#define INCLUDED_TUTORIALS_ADDER_H

#include <tutorials/api.h>
#include <gnuradio/sync_block.h>

namespace gr
{
namespace tutorials
{

/*!
 * \brief <+description of block+>
 * \ingroup tutorials
 *
 */
template<class T>
class TUTORIALS_API adder : virtual public gr::sync_block
{
public:
    typedef boost::shared_ptr<adder<T>> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of tutorials::adder.
     *
     * To avoid accidental use of raw pointers, tutorials::adder's
     * constructor is in a private implementation
     * class. tutorials::adder::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};
typedef adder<int> adder_ii;
typedef adder<float> adder_ff;
typedef adder<gr_complex> adder_cc;
} // namespace tutorials
} // namespace gr

#endif /* INCLUDED_TUTORIALS_ADDER_H */

