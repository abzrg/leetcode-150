-include ../make/common.mk
TOPIC = BIN-TREE-GNRL

# Add Targets to EXES:
EXECS = max-depth-binary-tree

TARGETS = $(addprefix $(BUILDDIR)/,$(EXECS))

all: $(TARGETS)

$(BUILDDIR):
	-@mkdir -pv $(BUILDDIR)

$(BUILDDIR)/%: %.cpp | $(BUILDDIR)
	@echo [C ${TOPIC}] $@
ifndef VERBOSE
	@$(CXX) $(CXXFLAGS) $< -o $@
else
	$(CXX) $(CXXFLAGS) $< -o $@
endif

clean:
	-@${RM} -fv $(TARGETS)

.PHONY: all clean
