# LibOB2


## Testing

```
python3.10 -m elm -s car
```

```
import obd

connection = obd.OBD("/dev/pts/1") # Use the device printed in the ELM emulator

cmd = obd.commands.SPEED # select an OBD command (sensor)

response = connection.query(cmd) # send the command, and parse the response

print(response.value) # returns unit-bearing values thanks to Pint
print(response.value.to("mph")) # user-friendly unit conversions

```