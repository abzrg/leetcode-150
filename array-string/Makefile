-include ../make/common.mk
TOPIC = array-string

# Add Targets to EXES:
EXECS = merge-sorted-array

TARGETS = $(addprefix $(BUILDDIR)/,$(EXECS))

all: $(TARGETS)

$(BUILDDIR):
	-@mkdir -pv $(BUILDDIR)

$(BUILDDIR)/%: %.cpp | $(BUILDDIR)
	@echo [C ${TOPIC}] $@
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-@${RM} -fv $(TARGETS)

.PHONY: all clean
