.PHONY: clean All

All:
	@echo "----------Building project:[ Stereotype_call - Debug ]----------"
	@cd "Stereotype_call" && "$(MAKE)" -f  "Stereotype_call.mk"
clean:
	@echo "----------Cleaning project:[ Stereotype_call - Debug ]----------"
	@cd "Stereotype_call" && "$(MAKE)" -f  "Stereotype_call.mk" clean
