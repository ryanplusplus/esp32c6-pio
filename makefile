.PHONY: all
all:
	@pio run

.PHONY: upload
upload:
	@pio run -t upload

.PHONY: run
run: upload
	@sleep 1.5
	@pio device monitor

.PHONY: monitor
monitor:
	@pio device monitor

.PHONY: clean
clean:
	@pio run -t clean
