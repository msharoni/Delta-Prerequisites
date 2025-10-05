import csv
from datetime import datetime
from typing import List, Optional

current_daf = 13
tasks = []
month = 10
Masechet = "Zevachim"
# The header columns in Todoist’s import CSV template:
HEADERS = [
    "TYPE",
    "CONTENT",
    "DESCRIPTION",
    "PRIORITY",
    "INDENT",
    "AUTHOR",
    "RESPONSIBLE",
    "DATE",
    "DATE_LANG",
    "TIMEZONE",
    "DURATION",
    "DURATION_UNIT",
    "meta",
    "DEADLINE",
    "DEADLINE_LANG"
]

def write_todoist_csv(
    filename: str,
    tasks: List[dict],
    default_date_lang: str = "en",
    default_timezone: Optional[str] = None
):
    """
    tasks: list of dicts, each dict may have keys:
        type, content, description, priority, indent,
        author, responsible, date, date_lang, timezone,
        duration, duration_unit, meta, deadline, deadline_lang
    default_date_lang: fallback for tasks without date_lang
    default_timezone: fallback timezone (e.g. "Asia/Jerusalem") or None
    """
    with open(filename, mode="w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=HEADERS)
        writer.writeheader()

        for t in tasks:
            row = {}
            # Fill required fields or defaults
            row["TYPE"] = t.get("type", "task")
            row["CONTENT"] = t.get("content", "")
            row["DESCRIPTION"] = t.get("description", "")
            row["PRIORITY"] = t.get("priority", "")
            row["INDENT"] = t.get("indent", "")
            row["AUTHOR"] = t.get("author", "")
            row["RESPONSIBLE"] = t.get("responsible", "")
            row["DATE"] = t.get("date", "")
            row["DATE_LANG"] = t.get("date_lang", default_date_lang)
            # If timezone provided per task, else default
            row["TIMEZONE"] = t.get("timezone", default_timezone or "")
            row["DURATION"] = t.get("duration", "")
            row["DURATION_UNIT"] = t.get("duration_unit", "")
            row["meta"] = t.get("meta", "")
            row["DEADLINE"] = t.get("deadline", "")
            row["DEADLINE_LANG"] = t.get("deadline_lang", default_date_lang)

            writer.writerow(row)

def write_full_month(days,start=1,year=2025,chaser = False):
    global tasks
    global month
    global current_daf
    global Masechet
    for i in range(days-start):
        tasks += [{
            "type": "task",
            "content": f"Daily Coding Problem ",
            "description": "Tehilim",
            "priority": "4",
            "indent": "1",
            "author": "",
            "responsible": "",
            "date": f"{year}-{month}-{start + i}",
            # date_lang and timezone can be omitted to use default
            "duration": "",
            "duration_unit": "",
            "meta": "",
            "deadline": "",
            "deadline_lang": "",
        }]
        current_daf %= 30
        current_daf += 1        
        if chaser and current_daf == 30:
            tasks += [{
            "type": "task",
            "content": f"Tehilim {current_daf}",
            "description": "Tehilim",
            "priority": "4",
            "indent": "1",
            "author": "",
            "responsible": "",
            "date": f"{year}-{month}-{start + i}",
            # date_lang and timezone can be omitted to use default
            "duration": "",
            "duration_unit": "",
            "meta": "",
            "deadline": "",
            "deadline_lang": "",
            }]
            current_daf = 1
        
    month %= 12
    month += 1

if __name__ == "__main__":
    # Example usage
    

    write_full_month(32,5)
    write_full_month(31)
    write_full_month(32)
    write_full_month(13,year=2026)
 
    month -= 1
    write_full_month(32,13,year =2026,chaser=True)
    write_full_month(29,year = 2026)
    write_full_month(32,year = 2026,chaser=True)
    write_full_month(31,year = 2026)
    write_full_month(17,year = 2026,chaser=True)

    write_todoist_csv("todoist_template.csv", tasks, default_date_lang="en", default_timezone="Asia/Jerusalem")
    print("CSV file written: todoist_template.csv")