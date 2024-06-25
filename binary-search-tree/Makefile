-include ../make/common.mk
TOPIC = BINARY-SEARCH-TREE

# Add Targets to EXES:
EXECS = min-absolute-diff-in-bst

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
