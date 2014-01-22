define subst-src-ext
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst %.S,%.o,$(patsubst %.s,%.o,$(1)))))
endef

define transform-c-to-o
$(strip $(2)): $(strip $(1))
	mkdir -p $(dir $(_tgt))
	$$(CC) $(strip $(3)) -c $$< -o $$@
endef

define transform-cpp-to-o
$(strip $(2)): $(strip $(1))
	mkdir -p $(dir $(_tgt))
	$$(CXX) $(strip $(3)) -c $$< -o $$@
endef

define transform-S-to-o
$(strip $(2)): $(strip $(1))
	mkdir -p $(dir $(_tgt))
	$$(CC) $(strip $(3)) -c $$< -o $$@
endef

define transform-s-to-o
$(strip $(2)): $(strip $(1))
	mkdir -p $(dir $(_tgt))
	$$(AS) $(strip $(3)) -c $$< -o $$@
endef

define compile-one-file
$(eval $(foreach f,$(filter %.c,$(1)),$(call transform-c-to-o,$(f),$(2),$(3))))
$(eval $(foreach f,$(filter %.cpp,$(1)) $(filter %.cc,$(1)),$(call transform-cpp-to-o,$(f),$(2),$(3))))
$(eval $(foreach f,$(filter %.S,$(1)),$(call transform-S-to-o,$(f),$(2),$(3))))
$(eval $(foreach f,$(filter %.s,$(1)),$(call transform-s-to-o,$(f),$(2),$(3))))
endef