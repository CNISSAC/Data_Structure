.PHONY: clean All

All:
	@echo "----------Building project:[ Section_vector - Debug ]----------"
	@cd "Section_vector" && "$(MAKE)" -f  "Section_vector.mk"
clean:
	@echo "----------Cleaning project:[ Section_vector - Debug ]----------"
	@cd "Section_vector" && "$(MAKE)" -f  "Section_vector.mk" clean
