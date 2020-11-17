/* -*- c++ -*- */

#define TUTORIALS_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "tutorials_swig_doc.i"

%{
#include "tutorials/adder.h"
%}

%include "tutorials/adder.h"
GR_SWIG_BLOCK_MAGIC2_TMPL(tutorials,adder_ii,adder<int>);
GR_SWIG_BLOCK_MAGIC2_TMPL(tutorials,adder_ff,adder<float>);
GR_SWIG_BLOCK_MAGIC2_TMPL(tutorials,adder_cc,adder<gr_complex>);