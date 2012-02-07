lie
===

A python module for computations with Lie groups, Lie algebras,
representations, root systems, and more.

Basic Information
-----------------

lie is based on the computer algebra package [LiE](http://www-math.univ-poitiers.fr/~maavl/LiE/),
written by M. A. A. van Leeuwen, A. M. Cohen and B. Lisser in the
early 90's.  LiE implemented a proprietary scripting language as a
wrapper for its mathematical algorithms.  While this language is
useful for interactive computations and short scripts, python is more
expressive and powerful.

lie provides python interfaces for the following objects in the LiE language:

 - grp: a Lie group
 - vec: a vector of integers
 - mat: a 2-dimensional matrix of integers
 - pol: a (multivariable) polynomial with integer coefficients

In addition, lie wraps some of these into abstract objects which
are more mathematically natural:

 - AbstractVec: a vector in the rational span of a root system of some
   Lie group. This includes roots, weights, and linear combinations.
 - weyl: a Weyl group element.
 - toral: a toral element.
 - rep : a Lie group representation.

Usage
-----

lie implements most functions from LiE
(see [the documentation](http://www-math.univ-poitiers.fr/~maavl/LiEman/manual.pdf)).

This example calculation shows how the 10 + 5bar + 1 representation of
SU(5) [contains a single standard model generation](http://en.wikipedia.org/wiki/Grand_Unified_Theory).

    Python 3.1 (r31:73578, Jun 27 2009, 21:49:46)
    >>> from lie import *

A4 is SU(5) in Cartan's classifiation, as we can see when we
pretty-print.

    >>> g = A4; g.pprint()
    'SU(5)'

A representation is shown as "group(highest-weight-vector)",
But physicists usually label representations by their dimension
(the b is for "bar", or "dual").

    >>> r = g.fund().dual() + g.alt_tensor(2) + g.trivial()
    >>> r
    A4(0,0,0,0) + A4(0,0,0,1) + A4(0,1,0,0)
    >>> r.pprint()
    '(1) + (5b) + (10)'

We can see that SU(2)xSU(3) is a subgroup of SU(5).
Next let's get the restriction matrix for SU(2)xSU(3) in SU(5), and
add the U(1) part by hand:

    >>> [h.pprint() for h in g.max_subgrps()]
    ['SU(4)', 'SO(5)', 'SU(2)xSU(3)']
    >>> m = g.res_mat(A1*A2)
    >>> m = m.transpose().concat(mat([[-2,1,-1,2]])).transpose()

Finally, we decompose r under the group SU(2)xSU(3)xU(1).
The first two numbers are the SU(2) and SU(3) rep dimensions,
and the third is the U(1) charge.

    >>> r.branch(A1*A2*T1, m).pprint() 
    '(1,1,0) + (1,1,6) + (1,3b,-4) + (1,3b,2) + (2,1,-3) + (2,3,1)'

Installation
------------

Requirements:

 - Python 3.1 or later (<http://www.python.org/>)
 - Cython (<http://www.cython.org/>)
 - gcc

Type "make" in the root directory.

Credits
-------

Written by [David Simmons-Duffin](http://davidsd.org) in 2009 for use in:
 
 - D. Poland and D. Simmons-Duffin, "Superconformal Flavor Simplified,"
   arXiv:0910.4585 [hep-ph].

This module basically wraps the C-source code from:

 - M. A. A. van Leeuwen, A. M. Cohen and B. Lisser, "LiE, A Package for
   Lie Group Computations", Computer Algebra Nederland, Amsterdam, ISBN
   90-74116-02-7, 1992

C-python bridge made possible by [Cython](http://www.cython.org/)
