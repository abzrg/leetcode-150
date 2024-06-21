-include ../make/common.mk
TOPIC = HASHMAP

# Add Targets to EXES:
EXECS = ransom-note

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
