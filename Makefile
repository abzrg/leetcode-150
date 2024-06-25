-include common.mk

$(if $(filter __%, $(MAKECMDGOALS)), \
	$(error targets prefixed with '__' are only for internal use))

# Supress entering and exit directory
ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

# Add topics here
TOPICS = stack hashmap array-string binary-tree-general intervals binary-search-tree
TARGET_TOPICS = $(addprefix __,$(TOPICS))

all: $(TARGET_TOPICS)

$(TARGET_TOPICS):
ifndef VERBOSE
	@echo '==>' [C $(shell echo $(patsubst __%,%,$@) | tr '[:lower:]' '[:upper:]')]
endif
	@$(MAKE) --directory $(patsubst __%,%,$@)

clean:
	-@for topic in $(TOPICS); do echo '==>' [CLEANING $$topic]; $(MAKE) --directory $${topic} clean; done

.PHONY: all clean $(TARGET_TOPICS)
