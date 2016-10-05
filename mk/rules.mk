# The compilation of software known as Bionic is distributed under the
# following terms:
# 
# Copyright (c) Christopher Friedt. All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

COMMA=,

define compiler-include-path
$(shell echo | @CC@ -v -x c -E - 2>&1 | grep -A 1 "^#include" | tail -n 1)
endef

define subst-src-ext
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(patsubst %.S,%.o,$(patsubst %.s,%.o,$(1))))))
endef

define src-to-obj
$(subst //,/,$(subst $(top_srcdir),$(top_builddir),$(dir $(1)))/$(2)$(strip $(call subst-src-ext,$(notdir $(1)))))
endef

# for some reason, can't use "mkdir -p $(dir $$@)", but "@CC@ $(strip $(3)) -c $$< -o $$@" works - go team automake!

define transform-c-or-S-to-o
$(strip $(2)): $(strip $(1)) $(4)
	mkdir -p $$(dir $$@)
	@CC@ $(strip $(3)) -c $$< -o $$@
endef

define transform-cpp-to-o
$(strip $(2)): $(strip $(1)) $(4)
	mkdir -p $$(dir $$@)
	@CXX@ $(strip $(3)) -c $$< -o $$@
endef

define transform-s-to-o
$(strip $(2)): $(strip $(1)) $(4)
	mkdir -p $$(dir $$@)
	@AS@ $(3) -c $$< -o $$@
endef

# $1 source file
# $2 tag (e.g. 'libc_common')
# $3 other dependencies e.g. $(SYSCALLS_STAMP)
define compile-one-file
$(eval _src = $(strip $(1)))
$(eval _tag = $(strip $(2)))
$(eval _tgt = $(call src-to-obj,$(_src),$(_tag)-))
$(eval $(_tag)_obj += $(_tgt))
$(eval $(foreach f,$(filter %.c,$(_src)) $(filter %.S,$(_src)),$(call transform-c-or-S-to-o,$(f),$(_tgt),$($(_tag)_cflags))))
$(eval $(foreach f,$(filter %.cpp,$(_src)) $(filter %.cc,$(_src)),$(call transform-cpp-to-o,$(f),$(_tgt),$($(_tag)_cxxflags))))
$(eval $(foreach f,$(filter %.s,$(_src)),$(call transform-s-to-o,$(f),$(_tgt),$($(_tag)_asflags)))) 
endef